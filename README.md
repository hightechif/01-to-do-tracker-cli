# To-Do Tracker CLI

A lightweight, efficient, and portable command-line task manager built in C. This tool allows you to manage your daily tasks directly from your terminal with low overhead and reliable persistence.

## Features

- **Add Tasks**: Quickly create new tasks with descriptions.
- **List Tasks**: View all your tasks with their current status.
- **Mark Complete**: Easily toggle tasks between pending and completed.
- **Delete Tasks**: Remove tasks from your list permanently.
- **Persistence**: Automatically saves your tasks to a local file, ensuring your data is safe between sessions.

## Quick Start

### Prerequisites

- A C compiler (e.g., `gcc` or `clang`)
- `make` build tool

### Installation

1. Clone the repository:
   ```bash
   git clone git@github.com:hightechif/01-to-do-tracker-cli.git
   cd 01-to-do-tracker-cli
   ```

2. Build the project:
   ```bash
   make
   ```

### Usage

```bash
# Add a new task
./build/todo add "Finish the project documentation"

# List all tasks
./build/todo list

# Mark a task as complete (using its ID)
./build/todo done 1

# Delete a task
./build/todo delete 1
```

## Project Structure

- `src/`: Source files (`.c`)
- `include/`: Header files (`.h`)
- `build/`: Compiled object files and binaries (ignored by git)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
