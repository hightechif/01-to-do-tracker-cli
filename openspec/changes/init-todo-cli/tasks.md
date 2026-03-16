## 1. Project Initialization

- [x] 1.1 Create directory structure: `src` and `include` folders
- [x] 1.2 Create `Makefile` for compiling the project

## 2. Core Task Models

- [x] 2.1 Define `Task` structure and constants in `include/task.h`
- [x] 2.2 Implement core task list logic (add, remove, toggle) in `src/task.c`

## 3. Persistence Implementation

- [x] 3.1 Define storage interface in `include/storage.h`
- [x] 3.2 Implement task serialization and file-writing in `src/storage.c`
- [x] 3.3 Implement task deserialization and file-reading in `src/storage.c`

## 4. CLI Driver and UI

- [x] 4.1 Implement argument parsing logic in `src/main.c`
- [x] 4.2 Create formatted output functions for task display
- [x] 4.3 Integrate task management and storage with CLI commands

## 5. Verification

- [ ] 5.1 Verify 'add' command persists tasks correctly
- [ ] 5.2 Verify 'list' command displays tasks accurately
- [ ] 5.3 Verify 'done' command updates completion status
- [ ] 5.4 Verify 'delete' command removes tasks from storage
