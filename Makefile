CXX = gcc
CXXFLAGS = -Wall -I./include
LDFLAGS = -lm
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin


SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/program: $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/program
	rm -f $(OBJ) $(EXECUTABLE)