## 1. Project Initialization

- [ ] 1.1 Create directory structure: `src` and `include` folders
- [ ] 1.2 Create `Makefile` for compiling the project

## 2. Core Task Models

- [ ] 2.1 Define `Task` structure and constants in `include/task.h`
- [ ] 2.2 Implement core task list logic (add, remove, toggle) in `src/task.c`

## 3. Persistence Implementation

- [ ] 3.1 Define storage interface in `include/storage.h`
- [ ] 3.2 Implement task serialization and file-writing in `src/storage.c`
- [ ] 3.3 Implement task deserialization and file-reading in `src/storage.c`

## 4. CLI Driver and UI

- [ ] 4.1 Implement argument parsing logic in `src/main.c`
- [ ] 4.2 Create formatted output functions for task display
- [ ] 4.3 Integrate task management and storage with CLI commands

## 5. Verification

- [ ] 5.1 Verify 'add' command persists tasks correctly
- [ ] 5.2 Verify 'list' command displays tasks accurately
- [ ] 5.3 Verify 'done' command updates completion status
- [ ] 5.4 Verify 'delete' command removes tasks from storage
