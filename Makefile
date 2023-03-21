CC = gcc
CFLAGS = -Iinclude -std=c99

all: main

bin/%.o: src/%.c
	@ echo "**1** Compilation du $<..."
	@$(CC) $(CFLAGS) -c -o $@ $< -fPIC

main:
	@echo " -- COMPILATION -- "
	@$(CC) $(CFLAGS) -o $@ src/maze.c $< -lm

clean:
	@echo " -- NETTOYAGE -- "
	@rm -f main

doc:
	@echo "Compilation de la documentation !!"
	@doxygen doc/Doxyfile

.PHONY: clean all doc