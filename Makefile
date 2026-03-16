CC = gcc
CFLAGS = -Wall -Iinclude
SRC = $(wildcard src/*.c)
BUILD_DIR = build
OBJ = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.c=.o)))
TARGET = $(BUILD_DIR)/todo

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
