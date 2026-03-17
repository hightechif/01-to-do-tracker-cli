## Context

The to-do tracker CLI currently uses a naive ID generation strategy: `new_id = list->count + 1`. This leads to ID reuse and collisions when tasks are deleted and new ones are added. For example, adding two tasks (IDs 1, 2) and deleting ID 1 results in a list with one task (ID 2). Adding a new task then assigns it ID 2 again, resulting in two tasks with the same ID.

## Goals / Non-Goals

**Goals:**
- Guarantee unique, monotonically increasing IDs for all tasks.
- Persist the ID counter across application restarts.
- Maintain backward compatibility with existing `tasks.txt` files where possible.
- Provide unit tests to verify the fix and prevent regressions.

**Non-Goals:**
- Implementing a full database system.
- Supporting ID resizing or compression.

## Decisions

- **State Management**: Modify the `TaskList` structure in `include/task.h` to include a `last_id` field.
- **ID Generation**: In `src/task.c`, update `task_add` to increment `list->last_id` and assign the new value to the task.
- **File Format Update**: The `tasks.txt` file will now optionally include a metadata line at the top to store the `last_id`.
    - Format: `# LAST_ID:<value>`
    - The `storage_load` function will be updated to parse this line if it exists.
    - If the metadata line is missing (old file format), `storage_load` will initialize `last_id` to the maximum ID found in the loaded tasks.
- **Storage Logic**: Update `storage_save` to always write the metadata line at the beginning of the file.

## Risks / Trade-offs

- **Format Change**: Adding a header line to `tasks.txt` might confuse users who manually edit the file.
    - *Mitigation*: Use a standard comment prefix (`#`) and keep the format human-readable.
- **Header Parsing**: `storage_load` needs to be robust against malformed headers.
    - *Mitigation*: Use careful string parsing and fallback to scanning task IDs if the header is missing or invalid.
