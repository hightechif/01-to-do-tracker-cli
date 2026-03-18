# Implementation Tasks

## 1. Integrate cJSON Library

- [x] 1.1 Download/Add `cJSON.h` to `include/`.
- [x] 1.2 Download/Add `cJSON.c` to `src/`.
- [x] 1.3 Update `Makefile` to include `src/cJSON.c` in the build process.

## 2. Refactor Storage Implementation

- [x] 2.1 Update `storage_save` in `src/storage.c` to build a cJSON object from `TaskList` and write it to the file.
- [x] 2.2 Update `storage_load` in `src/storage.c` to read the file, parse it as JSON, and populate `TaskList`.
- [x] 2.3 Implement the legacy fallback logic in `storage_load` to handle old pipe-delimited files.

## 3. Verification and Testing

- [x] 3.1 Update `tests/test_storage.c` to verify JSON serialization and deserialization.
- [x] 3.2 Add a test case for migrating from the old format to JSON.
- [x] 3.3 Ensure all existing tests pass with the new storage backend.
