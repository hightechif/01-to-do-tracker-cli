## ADDED Requirements

### Requirement: Command Line Argument Parsing
The system SHALL parse command-line arguments to determine the operation to perform. Supported commands MUST include `add`, `list`, `delete`, and `done`.

#### Scenario: Running the add command
- **WHEN** the command is `add "Buy groceries"`
- **THEN** the system adds a task with the description "Buy groceries"

#### Scenario: Running the list command
- **WHEN** the command is `list`
- **THEN** the system displays the current tasks

#### Scenario: Running the delete command
- **WHEN** the command is `delete 1`
- **THEN** the system removes task with ID 1

#### Scenario: Running the done command
- **WHEN** the command is `done 1`
- **THEN** the system marks task with ID 1 as complete

### Requirement: Help and Usage Display
The system SHALL display usage instructions when no arguments or invalid arguments are provided, or when the `help` command is used.

#### Scenario: No arguments provided
- **WHEN** the user runs the application without any arguments
- **THEN** the system displays the help manual

### Requirement: Formatted Console Output
The system SHALL display the task list in a readable, formatted table or list in the console.

#### Scenario: Displaying tasks in list
- **WHEN** the user runs the `list` command
- **THEN** the system outputs a list where each line represents a task showing [X] for complete and [ ] for incomplete
