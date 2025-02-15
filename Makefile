CC = g++
CFLAGS = -g -Wall -std=c++11
SRCS = main.cpp buildTree.cpp traversals.cpp
OBJS = main.o buildTree.o traversals.o
DEPS = $(SRCS) main.h node.h buildTree.h traversals.h
TARGET = P0
.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f *.o $(TARGET)

help:
	@echo "Usage: make [all|clean|help]"
	@echo "    all:    Build the $(TARGET) TARGETS"
	@echo "    clean:  Remove build artifacts"
	@echo "    help:   Print this help message"
