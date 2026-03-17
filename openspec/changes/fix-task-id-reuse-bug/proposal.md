## Why

The current task ID generation logic is based on the current number of tasks in the list. This leads to several issues:
1. **ID Collisions**: If tasks are deleted, the next task added may receive an ID that is already in use by another task in the list.
2. **Inconsistent Tracking**: Users rely on persistent IDs to track their tasks. Reusing IDs makes it difficult to refer to specific tasks reliably over time.

## What Changes

- **Update Task State**: Introduce a `next_id` or `last_id` counter in the `TaskList` structure to track the highest ID ever assigned.
- **Improved ID Generation**: Modify the `task_add` function to use and increment the persistent ID counter, ensuring every new task receives a unique, previously unused ID.
- **Persistence Update**: Update the storage mechanism to save and load the state of the ID counter, ensuring continuity across application restarts.
- **Unit Testing**: Add a regression test to verify that IDs remain unique and sequential even after multiple add/delete operations.

## Capabilities

### New Capabilities
- `unique-id-generation`: Ensures every task added to the system is assigned a unique, non-reusable ID for its lifetime.

### Modified Capabilities
- `task-management`: Update internal logic to handle persistent IDs instead of simple index-based IDs.
- `persistence`: Extend the storage format to include the `next_id` counter.

## Impact

- **Data Structures**: Modifies `TaskList` struct in `task.h`.
- **Logic**: Modifies `task_add` in `task.c`.
- **Storage**: Updates `storage_save` and `storage_load` in `storage.c`.
- **Testing**: New test case in `tests/test_task.c`.
- **Compatibility**: The new storage format will be backward compatible by defaulting the counter if not found in old files.
