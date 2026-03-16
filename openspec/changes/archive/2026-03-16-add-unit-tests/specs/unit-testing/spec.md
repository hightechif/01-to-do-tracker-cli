## ADDED Requirements

### Requirement: Task Logic Coverage
The test suite SHALL verify all operations on the task list, including adding tasks, deleting tasks by ID, and toggling completion status.

#### Scenario: Verify task addition
- **WHEN** multiple tasks are added through `task_add`
- **THEN** each task is assigned a unique ID and its description matches the input

#### Scenario: Verify task deletion
- **WHEN** a valid task ID is deleted
- **THEN** it is removed from the list and the list count decreases

#### Scenario: Verify task toggle
- **WHEN** a task is toggled
- **THEN** its completion status switches between 0 (TODO) and 1 (DONE)

### Requirement: Persistence Coverage
The test suite SHALL verify that tasks can be correctly serialized to and deserialized from a file.

#### Scenario: Verify saving and loading
- **WHEN** a task list is saved to a test file and then loaded back
- **THEN** the loaded list matches the originally saved list exactly

### Requirement: Test Runner Feedback
The test runner SHALL provide a clear summary of how many tests passed and how many failed.

#### Scenario: All tests pass
- **WHEN** all assertion checks succeed
- **THEN** the runner outputs "ALL TESTS PASSED" and exits with status 0

#### Scenario: At least one test fails
- **WHEN** any assertion check fails
- **THEN** the runner outputs details of the failure and exits with a non-zero status
