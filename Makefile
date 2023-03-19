# Makefile for SDL2 game

# Compiler
CC = g++

# Compiler flags
CFLAGS = -c -Wall -g

# Directories
SRCDIR = src
OBJDIR = build
BINDIR = build

# Targets
TARGET = $(BINDIR)/game
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

# Build executable
$(TARGET): $(OBJ)
	$(CC) $^ -o $@ -lSDL2 -lSDL2_image

# Build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

# Clean build files
clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/*

# Create directories
$(shell mkdir -p $(OBJDIR))
$(shell mkdir -p $(BINDIR))
