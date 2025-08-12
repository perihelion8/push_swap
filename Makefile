# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -Werror -Wextra -Iinclude -Isrc
# Add any extra include paths
CFLAGS  += -Isrc/sorter/arri -Isrc/sorter/list -Isrc/parser

# Name of the final executable
TARGET  := push_swap

# Find all source files (.c)
SRC     := $(shell find src -name '*.c')
# Convert src/*.c → build/*.o
OBJ     := $(SRC:src/%.c=build/%.o)

# Default target
all: $(TARGET)

# Link step
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Compile step (with mkdir -p to create folder structure in build/)
build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove build artifacts
clean:
	rm -rf build $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

