CC = gcc
CFLAGS = -Iinclude -std=c99

all: main

main:
	@echo "-- COMPILATION --"
	@$(CC) $(CFLAGS) -o $@ src/main.c src/labyrinthe.c $< -lm

clean:
	@echo "-- NETTOYAGE --"
	@rm -f main

doc:
	@echo "-- DOCUMENTATION --"
	@doxygen doc/Doxyfile

.PHONY: clean all doc