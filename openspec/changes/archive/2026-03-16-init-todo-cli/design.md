## Context

The project is a new C-based command-line utility for task management. There is no existing codebase, so this design establishes the foundational architecture and technical standards for the application.

## Goals / Non-Goals

**Goals:**
- Provide a responsive CLI for adding, listing, deleting, and completing tasks.
- Ensure data persists between application runs using simple file storage.
- Maintain a clean, modular code structure in C.
- Implement robust error handling for file I/O and user input.

**Non-Goals:**
- Supporting multiple users or shared databases.
- Providing a graphical user interface (GUI).
- Implementing advanced features like recurring tasks, priorities, or categories in the initial version.
- Synchronization with external services.

## Decisions

- **Architecture**: Monolithic but modular approach. Separate files for task logic (`task.c/h`), persistence (`storage.c/h`), and the main CLI driver (`main.c`).
- **Data Structure**: An array of `Task` structs. Each struct will contain an `int id`, `int is_completed`, and `char description[256]`.
- **Persistence Layer**: A human-readable text file (e.g., `tasks.txt`). Format: `ID|STATUS|DESCRIPTION`. This choice simplifies debugging and allows users to manually edit the file if necessary.
- **CLI Parsing**: Manual parsing of `argc` and `argv` for the initial version to keep dependencies minimal.
- **Build System**: Makefile for standard compilation and cleanup tasks.

## Risks / Trade-offs

- **Memory Management**: Using a fixed-size array for tasks limits the capacity. 
    - *Mitigation*: Set a reasonable default (e.g., 100 tasks) and implement checks to prevent overflows.
- **File Integrity**: Risk of data loss if writing to the file is interrupted.
    - *Mitigation*: Write to a temporary file and use `rename()` for atomic updates.
- **Concurrency**: No support for multiple instances writing to the same file.
    - *Mitigation*: For a single-user CLI tool, this is considered acceptable risk; documented in non-goals.
