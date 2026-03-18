## ADDED Requirements

### Requirement: json-file-format
The application must save and load task data using a valid JSON format that encompasses all task properties and metadata.

#### Scenario: Successful JSON save
- **WHEN** I have a list with 2 tasks and a `last_id` of 2
- **AND** I save the list to `tasks.json`
- **THEN** The file must contain a valid JSON object with `last_id` and a `tasks` array.

#### Scenario: Successful JSON load
- **WHEN** I load a valid `tasks.json` file
- **THEN** All tasks must be correctly populated in the application memory with their corresponding IDs, statuses, and descriptions.

### Requirement: backward-compatibility-migration
The application should be able to migrate data from the old pipe-delimited format to JSON during the first load.

#### Scenario: Legacy format migration
- **WHEN** I load a file in the old `ID|STATUS|DESCRIPTION` format
- **THEN** The application should successfully parse the tasks
- **AND** Upon the next save, the file should be rewritten in valid JSON format.
