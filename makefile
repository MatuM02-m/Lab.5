SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build
OBJ_DIR = ${BUILD_DIR}/obj
BIN_DIR = ${BUILD_DIR}/bin
PROGRAM = ${BIN_DIR}/lab5
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))

-include $(OBJ_DIR)/*.d

all : $(PROGRAM)

$(PROGRAM): $(OBJ_FILES) | $(BIN_DIR)
	@echo "Linking all object files to create the executable"
	@mkdir -p $(BIN_DIR)
	$(CC) -o $(PROGRAM) $(OBJ_FILES)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "Compiling $< to $@"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -MMD -D ALUMNOS_MAX_INSTANCIAS=4

$(OBJ_DIR) : | $(BUILD_DIR)
	mkdir $(OBJ_DIR)

$(BUILD_DIR) : 
	mkdir $(BUILD_DIR)

$(BIN_DIR) : | $(BUILD_DIR)
	mkdir $(BIN_DIR)

clean:
	@echo "Cleaning up build files"
	@rm -rf $(BUILD_DIR)

doc:
	@echo "Generating documentation with Doxygen"
	mkdir -p ${BUILD_DIR}/doc
	doxygen Doxyfile

info:
	@echo "OBJ_FILES= $(OBJ_FILES)"

run: all
	@echo "Running the program"
	@$(PROGRAM)
	@echo "Program finished running"	