## ADDED Requirements

### Requirement: monotonically-increasing-ids
Every new task must be assigned an ID that is strictly greater than any ID previously assigned in the current or previous sessions.

#### Scenario: ID persistence after deletion
- **WHEN** I add 'First Task' (ID: 1)
- **AND** I add 'Second Task' (ID: 2)
- **AND** I delete task with ID: 1
- **AND** I add 'Third Task'
- **THEN** 'Third Task' must have ID: 3

### Requirement: persistent-id-counter
The state of the task ID counter must be saved to disk so that IDs remain unique across application restarts.

#### Scenario: ID continuity after restart
- **WHEN** I add 'First Task' (ID: 1)
- **AND** I add 'Second Task' (ID: 2)
- **AND** I close and restart the application
- **AND** I add 'Third Task'
- **THEN** 'Third Task' must have ID: 3
