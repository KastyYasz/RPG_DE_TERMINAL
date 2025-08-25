CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
BIN = rpg

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(BIN)
