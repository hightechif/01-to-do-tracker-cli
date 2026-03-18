## Requirements

### Requirement: task-creation
The system SHALL allow users to create a new task with a text description. Each task MUST be assigned a unique numeric ID.

#### Scenario: Successful task creation
- **WHEN** the user provides a valid non-empty description
- **THEN** it is assigned a unique ID and a confirmation message is returned.

### Requirement: unique-id-generation
Every new task must be assigned an ID that is strictly greater than any ID previously assigned in the current or previous sessions, even if tasks have been deleted.

#### Scenario: ID persistence after deletion
- **WHEN** I add Task 1 (ID: 1) and Task 2 (ID: 2)
- **AND** I delete Task 1
- **AND** I add Task 3
- **THEN** Task 3 must have ID: 3.

### Requirement: task-deletion
The system SHALL allow users to delete an existing task by specifying its ID.

#### Scenario: Successful task deletion
- **WHEN** the user provides the ID of an existing task
- **THEN** the task is removed from the list and the list count decreases.

#### Scenario: Deleting non-existent task
- **WHEN** the user provides an ID that does not exist 
- **THEN** the system returns an error message indicating the task was not found.

### Requirement: task-completion-toggle
The system SHALL allow users to mark a task as complete or incomplete.

#### Scenario: Toggling task status
- **WHEN** I specify the ID of a task
- **THEN** its status switches between TODO and DONE.

### Requirement: task-listing
The system SHALL allow users to view all tasks currently in the list, showing their ID, status, and description.

#### Scenario: Viewing all tasks
- **WHEN** I request the task list
- **THEN** the system displays all tasks in a formatted list.
