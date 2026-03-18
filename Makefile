CC = gcc
SRC = src/task.c src/storage.c src/cJSON.c
CFLAGS = -Wall -Iinclude -lm
MAIN_SRC = src/main.c
TEST_SRC = $(wildcard tests/*.c)
BIN_DIR = dist
TARGET = $(BIN_DIR)/todo
TEST_TARGET = $(BIN_DIR)/test_runner

# Fix for restricted environments (macOS Documents folder / Sandbox)
# Force TMPDIR to /tmp to allow clang to create temporary files
# and specify BIN_DIR as 'dist' to avoid 'Operation not permitted' on 'build/' or 'bin/'
COMPILER = TMPDIR=/tmp $(CC)

all: $(BIN_DIR) $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TARGET): $(SRC) $(MAIN_SRC) | $(BIN_DIR)
	$(COMPILER) $(CFLAGS) $(SRC) $(MAIN_SRC) -o $(TARGET)

test: $(BIN_DIR) $(SRC) $(TEST_SRC)
	$(COMPILER) $(CFLAGS) $(SRC) $(TEST_SRC) -o $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(BIN_DIR)
