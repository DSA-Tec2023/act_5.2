# Makefile for a project with main.cpp and hash.hpp

# Compiler and flags
CC = g++
CFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp
HEADERS = hash.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = my_program

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to build object files from source files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

