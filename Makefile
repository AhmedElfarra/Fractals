CC = g++

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := . 

EXE := $(BIN_DIR)./output
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -MMD -MP # -I is a preprocessor flag, not a compiler flag
CFLAGS   := -Wall              # some warnings about bad code
LDFLAGS  := -Llib              # -L is a linker flag
LDLIBS   := -lm                # Left empty if no libs are needed
 
 .PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)


# all: $(EXE)

# output: main.o Fractal.o ComplexNumber.o
# 	${CC} main.o Fractal.o ComplexNumber.o -o output

# main.o: main.cpp
# 	${CC} -c main.cpp

# Fractal.o: Fractal.cpp Fractal.h
# 	${CC} -c Fractal.cpp

# ComplexNumber.o: ComplexNumber.cpp ComplexNumber.h
# 	${CC} -c ComplexNumber.cpp

# clean: 
# 	rm *.o output
