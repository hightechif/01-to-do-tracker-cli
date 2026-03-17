# Implementation Tasks

## 1. Update Core Data Structures

- [x] 1.1 Add `i32 last_id` to the `TaskList` struct in `include/task.h`.
- [x] 1.2 Initialize `last_id = 0` in `task_init` within `src/task.c`.

## 2. Refactor ID Generation

- [x] 2.1 Modify `task_add` in `src/task.c` to increment `list->last_id` and assign it to the new task.
- [x] 2.2 Remove the old logic that used `list->count + 1` for ID assignment.

## 3. Enhance Persistence Mechanism

- [x] 3.1 Update `storage_save` in `src/storage.c` to prepend a metadata line `# LAST_ID:<value>` to the storage file.
- [x] 3.2 Update `storage_load` in `src/storage.c` to parse the metadata line if present.
- [x] 3.3 Implement a fallback in `storage_load` to calculate `last_id` from existing tasks if the metadata header is missing.

## 4. Verification and Testing

- [x] 4.1 Add a unit test in `tests/test_task.c` that reproduces the reported bug and verifies the fix.
- [x] 4.2 Run all tests using `make test` to ensure no regressions in existing functionality.
