# To-Do Tracker CLI

A lightweight, efficient, and portable command-line task manager built in C. This tool allows you to manage your daily tasks directly from your terminal with low overhead and reliable persistence.

## Features

- **Add Tasks**: Quickly create new tasks with descriptions.
- **List Tasks**: View all your tasks with their current status.
- **Mark Complete**: Easily toggle tasks between pending and completed.
- **Delete Tasks**: Remove tasks from your list permanently.
- **Persistence**: Automatically saves your tasks to `tasks.json`.
- **Automated Testing**: Includes a built-in unit test suite for verifying core logic.

## Quick Start

### Prerequisites

- A C compiler (e.g., `gcc` or `clang`)
- `make` build tool

### Installation & Build

1. Clone the repository:
   ```bash
   git clone git@github.com:hightechif/01-to-do-tracker-cli.git
   cd 01-to-do-tracker-cli
   ```

2. Build the project:
   ```bash
   make
   ```

### Running Tests

To verify the application logic, run the automated tests:
```bash
make test
```

### Usage

The executable is located in the `dist/` directory.

```bash
# Add a new task
./dist/todo add "Finish the project documentation"

# List all tasks
./dist/todo list

# Mark a task as complete (using its ID)
./dist/todo done 1

# Delete a task
./dist/todo delete 1
```

## Project Structure

- `src/`: Core implementation files (`task.c`, `storage.c`, `main.c`).
- `include/`: API definitions and header files.
- `tests/`: Unit tests and a custom lightweight test harness.
- `dist/`: Compiled binaries and test runners (ignored by git).
- `openspec/`: Project specifications and change history.

## Development

The project uses a custom Makefile that automatically handles build dependencies and includes a dedicated testing target. It is designed to be compatible with restricted environments (like macOS sandbox) by using `/tmp` for intermediate compilation files.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
