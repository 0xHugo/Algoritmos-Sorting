SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c)
EXECUTABLE = algoSorting

CC = gcc
CFLAGS = -w
LDFLAGS =

compile: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

