## Requirements

### Requirement: cli-argument-parsing
The system SHALL parse command-line arguments to determine the operation to perform. Supported commands MUST include `add`, `list`, `delete`, and `done`.

#### Scenario: Running supported commands
- **WHEN** I run `./todo add "Buy milk"`
- **THEN** a task is added with that description.
- **WHEN** I run `./todo list`
- **THEN** the current tasks are displayed.

### Requirement: help-usage-display
The system SHALL display usage instructions when no arguments or invalid arguments are provided, or when the `help` command is used.

#### Scenario: Running with no arguments
- **WHEN** I run the application without any arguments
- **THEN** the system displays the help manual.

### Requirement: console-output-formatting
The system SHALL display the task list in a readable, formatted list in the console.

#### Scenario: Formatted list output
- **WHEN** listing tasks
- **THEN** each line represents a task showing [X] for complete and [ ] for incomplete alongside its ID.
