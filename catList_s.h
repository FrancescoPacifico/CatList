#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* EN:
 * For a better general understaing of lists made of nodes, please refer to catList.h in this reposiroty.
 * Nodes must now contain a pointer to char (to point a string).
 * ITA:
 * Per una migliore comprensione generale delle liste fatte di nodi, fare riferimento a catList.h in questa repository.
 * I nodi ora devono contenere un puntatore a char (per puntare una stringa). */

struct node_s {
	char *key;
	struct node_s *prev, *succ;
};

struct node_s *newList_s(void);
struct node_s *append0_s(struct node_s *, char *);
struct node_s *pop0_s(struct node_s *);
void printList_s(struct node_s *);

/* EN:
 * No changes in the newList function.
 * ITA:
 * Nessun cambiamento nella funzione newList. */

struct node_s *newList_s(void) {
	return NULL;
}

/* EN:
 * When we assign a value to 'p -> key', we must first alloc enough space to store the input string.
 * It's important not to just type 'p -> key = s', because in this way we would just make both the pointers to point the same string.
 * So we call strlen from string header to calculate the size to alloc for 'p -> key'. We alloc 'sizeof(char) * (strlen(s) + 1)'.
 * You won't see any 'sizeof(char)' below, because it would return 1 (1 char = 1 byte) and we add 1 to strlen(s) because this fucntion doesn't
 * consider the last character of the string '\0' when it calculates the length.
 * After having stored enough memory for the string, we can finally copy it using the strcpy function from string header.
 * ITA:
 * Quando assegnamo un valore a 'p -> key', dobbiamo prima allocare abbastanza spazio per memorizzare la stringa in input.
 * E' importante non limitarsi a scrivere 'p -> key = s', perchè, in questo modo, faremmo semplicemente puntare entrambi i puntatori alla stessa stringa.
 * Dunque chiamiamo strlen dall'intestazione string per calcolare lo spazzio da allocare per 'p -> key'. Allochiamo 'sizeof(char) * (strlen(s) + 1)'.
 * Non vedrai alcun 'sizeof(char)' nel codice qui sotto, perchè equivarrebbe a 1(1 char = 1 byte) e aggiungiamo 1 a strlen(s) perchè questa funzione non considera l'ultimo
 * carattere della stringa '\0' quando ne calcola la lunghezza.
 * Dopo aver allocato memoria sufficiente per la stringa, possiamo finalmente copiarla usando la funzione strcpy dell'intestazione string. */

struct node_s *append0_s(struct node_s *a, char *s) {
	struct node_s *p = malloc(sizeof(struct node_s));
	p -> key = malloc(strlen(s) + 1), p -> prev = NULL, p -> succ = a;
	strcpy(p -> key, s);
	if(a != NULL) {
		a -> prev = p;
	}
	return p;
}

/* EN:
 * When we pop a node from the list we must call the free function from stdlib header to free the space pointed by a pointer.
 * In this case, beacause the nodes are made of a pointer to char, we must free the memory pointed by this pointer first, and then the one pointed by the pointer to node.
 * ITA:
 * Quando eliminiamo un nodo dalla lista dobbiamo invocare la funzione free dell'intestazione stdlib per liberare lo spazio puntato da un puntatore.
 * In questo caso, poichè i nodi sono composti da un puntatore a char, dobbiamo prima liberare la memoria puntata da questo puntatore, e poit quella puntata dal puntatore a nodo. */

struct node_s *pop0_s(struct node_s *a) {
	struct node_s *p = NULL;
	if(a != NULL) {
		p = a -> succ;
		if(p != NULL) {
			p -> prev = NULL;
		}
		free(a -> key);
		free(a);
	}
	return p;
}

void printList_s(struct node_s *a) {
	for(; a != NULL; a = a -> succ) {
		printf("%s\n", a -> key);
	}
}
