COMPILER=clang++
TARGET=build/main
FLAGS=-Wall -Wextra -std=c++20
SRC_FOLDER=src
INCLUDE_FOLDER=include
SRC=$(wildcard $(SRC_FOLDER)/*.cc)
OBJ=$(patsubst $(SRC_FOLDER)/%.cc,build/%.o,$(SRC))
DEPS=$(OBJ:.o=.d)

# Add include folder to compilation flags
CPPFLAGS=-I$(INCLUDE_FOLDER)

# Build the executable
build: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	$(COMPILER) $(FLAGS) -o $@ $^

# Compile source files to object files with dependency generation
build/%.o: $(SRC_FOLDER)/%.cc
	@mkdir -p $(dir $@)
	$(COMPILER) $(FLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

# Include auto-generated dependencies
-include $(DEPS)

run: build
	./$(TARGET)

clean:
	rm -rf build

.PHONY: build run clean
