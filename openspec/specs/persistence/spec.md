## Requirements

### Requirement: data-persistence
The system SHALL save the state of the task list to a local file (`tasks.json`) to ensure data is preserved between executions.

#### Scenario: Saving tasks after modification
- **WHEN** a task is added, deleted, or updated
- **THEN** the system writes the updated task list to the data file in JSON format.

### Requirement: data-loading
The system SHALL attempt to load existing tasks from the data file upon startup.

#### Scenario: Application startup with existing JSON data
- **WHEN** the application starts and a valid `tasks.json` file exists
- **THEN** the system populates the task list with the data from the file.

#### Scenario: Application startup with no data file
- **WHEN** the application starts and no data file is found
- **THEN** the system starts with an empty task list and creates the file upon the first save operation.

### Requirement: serialization-format
The system SHALL use a valid JSON format for storing tasks that includes the `last_id` metadata and a `tasks` array containing individual task objects.

#### Scenario: JSON task structure
- **WHEN** saving tasks
- **THEN** each task object includes `id`, `is_completed`, and `description`.

### Requirement: backward-compatibility-migration
The application MUST be able to migrate data from the legacy pipe-delimited format to JSON during the first load operation.

#### Scenario: Legacy format migration
- **WHEN** I load a file in the old `ID|STATUS|DESCRIPTION` format
- **THEN** the application should successfully parse the tasks
- **AND** upon the next save, the file should be rewritten in valid JSON format.
