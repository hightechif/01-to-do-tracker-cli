## Requirements

### Requirement: task-logic-coverage
The test suite SHALL verify all operations on the task list, including adding tasks, deleting tasks by ID, and toggling completion status.

#### Scenario: Logic verification
- **WHEN** running unit tests
- **THEN** tasks are created with unique IDs and toggled/deleted correctly in application memory.

### Requirement: persistence-coverage
The test suite SHALL verify that tasks can be correctly serialized to and deserialized from a file, including backward compatibility migration.

#### Scenario: Persistence verification
- **WHEN** saving and loading from a test file
- **THEN** data integrity is maintained across the JSON format.

### Requirement: test-runner-feedback
The test runner SHALL provide a clear summary of how many tests passed and how many failed.

#### Scenario: Passing results
- **WHEN** all assertion checks succeed
- **THEN** the runner outputs "ALL TESTS PASSED" and exits with status 0.
