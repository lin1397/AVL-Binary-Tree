# VARIABLES
NAME = main
EXECUTABLE = test_$(NAME)
SRC_C = main.c insert.c print.c destory.c avl.c
SRC_H = btree.h
CC = gcc
CFLAGS = -g -std=c11 -Wall -Wshadow -Wvla -pedantic -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable

# RULES
$(EXECUTABLE): $(SRC_C) $(SRC_H)
	$(CC) $(CFLAGS) $(SRC_C) -o $(EXECUTABLE)

test: $(EXECUTABLE)
	./$(EXECUTABLE)

valgrind: $(EXECUTABLE)
	valgrind --leak-check=full --track-origins=yes ./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
