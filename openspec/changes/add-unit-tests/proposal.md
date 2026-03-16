## Why

As the project grows, manual verification of task operations becomes tedious and error-prone. Automated unit tests will ensure that core logic (adding, deleting, toggling tasks) and persistence (saving/loading) remain correct after future changes.

## What Changes

- **Testing Infrastructure**: Integrate a lightweight C testing framework or a custom test harness.
- **Unit Tests for Task Logic**: Implement tests for all functions in `src/task.c`.
- **Unit Tests for Storage**: Implement tests for saving and loading tasks in `src/storage.c`, using temporary files.
- **Build System Integration**: Add a `make test` command to compile and run all unit tests automatically.

## Capabilities

### New Capabilities
- `unit-testing`: A suite of automated tests for task management and persistence.

### Modified Capabilities
- (None - this adds the testing capability)

## Impact

This change introduces a new `tests/` directory containing test source files. It also modifies the `Makefile` to support test compilation and execution. Production code is not modified except for potential minor refactoring to improve testability.
