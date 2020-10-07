CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -g
OBJ_TABLEAU = tableaux/fonctions.o tableaux/tableau.o
OBJ_LISTE = listes/fonctions.o listes/liste.o

6all:tableau liste

tableau: $(OBJ_TABLEAU)
	$(CC) -o $@ $^ $(CFLAGS)

liste: $(OBJ_LISTE)
	$(CC) -o $@ $^ $(CFLAGS)

tableau/%.o: tableau/%.c
	$(CC) -o $@ $< $(CFLAGS) -c

liste/%.o: liste/%.c
	$(CC) -o $@ $< $(CFLAGS) -c

.PHONY: clean
clean:
	rm listes/*.o
	rm tableaux/*.o
	rm -f tableau
	rm -f liste
