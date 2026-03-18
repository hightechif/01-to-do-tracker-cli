## Why

The current pipe-delimited storage format (`ID|STATUS|DESCRIPTION`) is simple but fragile and difficult to extend. As the application grows, we may want to add features like task categories, priorities, or timestamps. JSON provides a standardized, structured, and extensible format that is easy to parse and widely supported.

## What Changes

- **Storage Format**: Replace the custom pipe-delimited format with a JSON-based format.
- **Dependency Integration**: Integrate a lightweight C JSON library (e.g., cJSON) to handle serialization and deserialization.
- **Storage Implementation**: Rewrite `storage_save` and `storage_load` in `src/storage.c` to use the JSON library.
- **Build System**: Update the `Makefile` to include the JSON library in the compilation process.

## Capabilities

### New Capabilities
- `json-persistence`: Provides structured data storage and retrieval using the JSON format.

### Modified Capabilities
- `persistence`: Transition the underlying storage mechanism from plain text to JSON.

## Impact

- **Codebase**: Major changes to `src/storage.c`.
- **Dependencies**: Introduction of a JSON library (likely cJSON).
- **Data**: Existing `tasks.json` files will need to be migrated or will be incompatible with the new format (unless a migration path is provided).
- **Build**: `Makefile` updates for library linking.
