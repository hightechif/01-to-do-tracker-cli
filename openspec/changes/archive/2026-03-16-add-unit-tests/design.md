## Context

The project currently only has manual verification through the CLI. To maintain high code quality, we need an automated unit testing suite.

## Goals / Non-Goals

**Goals:**
- Implement a lightweight, single-header or macro-based testing framework.
- Achieve high branch/logical coverage for `task.c` and `storage.c`.
- Integrate testing into the build process (`make test`).

**Non-Goals:**
- GUI or complex integration tests.
- Performance profiling or benchmark testing.
- Using a heavy C++ testing framework like GTest.

## Decisions

- **Framework**: Use a simple macro-based harness (defined in `tests/test_harness.h`) to minimize external dependencies.
- **Organization**: Create a `tests/` directory. Each source file will have a corresponding test file (e.g., `tests/test_task.c`).
- **Data Isolation**: Persistence tests will use a separate filename (e.g., `test_tasks.json`) to avoid corrupting the user's actual task data.
- **Reporting**: The test runner will print the file and line number of any failure to allow easy debugging.

## Risks / Trade-offs

- **Test Infrastructure Maintenance**: A custom harness adds code that needs to be maintained.
    - *Mitigation*: Keep the harness extremely simple (under 50 lines).
- **File System Access**: Storage tests write to disk.
    - *Mitigation*: Always clean up the test files after the test run finishes.
