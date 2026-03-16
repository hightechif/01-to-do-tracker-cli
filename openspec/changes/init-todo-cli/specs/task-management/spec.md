## ADDED Requirements

### Requirement: Task Creation
The system SHALL allow users to create a new task with a text description. Each task MUST be assigned a unique numeric ID for the current session.

#### Scenario: Successful task creation
- **WHEN** the user provides a valid non-empty description
- **THEN** the task is added to the task list and a confirmation is returned

### Requirement: Task Deletion
The system SHALL allow users to delete an existing task by specifying its ID.

#### Scenario: Successful task deletion
- **WHEN** the user provides the ID of an existing task
- **THEN** the task is removed from the list

#### Scenario: Deleting non-existent task
- **WHEN** the user provides an ID that does not exist in the list
- **THEN** the system returns an error message indicating the task was not found

### Requirement: Task Completion Status
The system SHALL allow users to mark a task as complete or incomplete.

#### Scenario: Marking task as complete
- **WHEN** the user specifies the ID of a pending task to be marked as complete
- **THEN** the task's status is updated to completed

#### Scenario: Marking task as incomplete
- **WHEN** the user specifies the ID of a completed task to be marked as incomplete
- **THEN** the task's status is reverted to pending

### Requirement: Task Listing
The system SHALL allow users to view all tasks currently in the list, showing their ID, status, and description.

#### Scenario: Viewing all tasks
- **WHEN** the user requests to see the task list
- **THEN** the system displays all tasks with their completion status and IDs
