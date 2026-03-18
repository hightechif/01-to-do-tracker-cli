## Context

The application currently uses a custom text-based storage format. While functional, it lacks the flexibility needed for future feature enhancements. This design details the migration to a JSON-based storage system using the lightweight `cJSON` library.

## Goals / Non-Goals

**Goals:**
- Implement JSON-based serialization and deserialization for the task list.
- Maintain support for the `last_id` counter within the JSON structure.
- Ensure the application can still build and run in restricted environments.
- Provide a clear structure for future task metadata.

**Non-Goals:**
- Implementing a full-featured JSON query engine.
- Supporting complex nested task structures in this iteration.

## Decisions

- **Library Choice**: `cJSON` will be used for JSON processing. It is chosen for its simplicity, small footprint (one `.c` and one `.h` file), and ease of integration into C projects.
- **Schema**:
    ```json
    {
      "last_id": 5,
      "tasks": [
        {
          "id": 1,
          "is_completed": false,
          "description": "Example task"
        }
      ]
    }
    ```
- **Project Structure**:
    - `include/cJSON.h`: The header for the JSON library.
    - `src/cJSON.c`: The implementation of the JSON library.
    - `src/storage.c`: Updated to use `cJSON` for file I/O.
- **Backward Compatibility**: `storage_load` will first attempt to parse the file as JSON. If parsing fails, it will attempt to load the file using the legacy pipe-delimited parser to ensure a smooth transition for existing users. Once loaded, the next save will convert the data to the new JSON format.

## Risks / Trade-offs

- **Dependency**: Adds a third-party library dependency.
    - *Mitigation*: Use a well-known, minimal library (`cJSON`) and include its source directly in the project to avoid external linking issues.
- **Performance**: JSON parsing is slightly more resource-intensive than simple string splitting.
    - *Mitigation*: For small task lists (up to 100 as per `MAX_TASKS`), the performance difference is negligible.
- **File Size**: JSON is more verbose than the current pipe-delimited format.
    - *Mitigation*: The increase in file size is minimal for the expected data volume.
