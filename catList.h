#include <stdio.h>
#include <stdlib.h>

/* ENG:
 * We are building a list made of nodes, where every node contains a value (integer value, in this case)
 * and two pointers: one to the previous node, and one to the next one.
 * Obviously there's no previous node to the first of the list as there's no node after the last. We'll
 * see how to manage these two cases later.
 * ITA:
 * Costruiremo una lista fatta di nodi, nella quale ogni nodo contiene un valore (intero, in questo caso)
 * e due puntatori: uno al nodo precedente, e uno al nodo successivo.
 * Ovviamente non c'è alcun nodo precedente al primo, come non ce n'è alcuno dopo l'ultimo. Vedremo come
 * gestire questi due casi successivamente. */

struct node {
	int key;
	struct node *prev, *succ;
};

/* ENG:
 * In order to manage a list like this we'll need some functions:
 * -One to create the list.
 * -One to add an item to the list.
 * -One to remove an item from the list.
 * ITA:
 * Per gestire una lista di questo tipo avremo bisogno di alcune funzioni:
 * -Una per creare la lista.
 * -Una per aggiungere un elemento alla lista.
 * -Una per rimuovere un elemento dalla lista. */

/* ENG:
 * Despite our list is built as a series of nodes, we'll use just one pointer to node to call it.
 * It's the same thing we do with "normal" array: the name of the array is a pointer to its first element.
 * In our case the list name will be a pointer to its first node.
 * ITA:
 * Nonostante la nostra lista sia costruita come una serie di nodi, useremo semplicemente un puntatore a nodo per chiamarla.
 * E' la stessa cosa che facciamo con i "normali" array: il nome dell'array è un puntatore al suo primo elemento.
 * Nel nostro caso il nome della lista sarà un puntatore al suo primo nodo. */

/* ENG:
 * This first function takes nothing as input and returns NULL, a pointer to nothing. This perfectly represents a void list,
 * that's what we are building by calling this function. Obviously, we could just write 'struct node *new_list = NULL' in our main
 * function, but using an auxiliary function is always a good thing.
 * ITA:
 * Questa prima funzione non prende nulla in input e retstituisce NULL, un puntatore a niente. Ciò rappresenta perfettamente una lista vuota,
 * che è ciò che stiamo costruendo chiamando questa funzione. Ovviamente, potremmo semplicemente scrivere 'struct node *new_list = NULL' nella
 * nostra funzione main, ma usare una funzione ausiliaria è sempre una buona cosa. */


struct node *newList(void) {
	return NULL;
}

/* ENG:
 * Now we are building a function that will help us to append an element to the head of a list.
 * This function takes a list (that could be void) and an integer that will be put inside a node and then attached to the list as inputs.
 * This node will be the new first node of our list, so the node that will identify the list itself.
 * The first step is to create a pointer to node, which must point to a specific amount of memory. That's why we call the malloc
 * function, from the stdlib header. This amount of memory must be enough to store a node, that will be pointed by 'p'.
 * Then, we have to fill this node:
 * -The key will be 'n', the second input of the functiont.
 * -The previous node of 'p' is... nothing, because 'p' will be the first node of the list.
 * -Afetr 'p' we must attach the "old" list, that was identified by 'a' (the first node of it).
 * So we created the node and managed to attach it to the top of the list (its head), but it's not over yet.
 * In fact, 'a' previous node is not NULL anymore, because 'a' is not the first node anymore.
 * So, if 'a' is not NULL (if the input list was not a void list = we are not adding 'p' as a first node of a list), we must
 * set 'p' as the previous node of 'a'.
 * Finally, we can return 'p', the new first node that identifies the list.
 * ITA:
 * Ora stiamo costruiremo una funzione che ci aiuterà ad aggiungere un elemento in testa alla lista.
 * Questa funzione prende in input una lista (che potrebbe essere vuota) e un intero che sarà inserito in un nodo e successivamente aggiunto alla lista.
 * Questo nodo sarà il nuovo primo nodo della nostra lista, dunque il nodo che identificherà la lista stessa.
 * Il primo passo è creare un puntatore a nodo, che deve puntare ad una specifica quantità di memoria. E' per questo che chiamiamo la funzione malloc,
 * dell'intestazione stdlib. Questa quantità di memoria deve essere sufficiente per contenere un nodo, il quale sarà puntato da 'p'.
 * Successivamente dobbiamo riempire questo nodo:
 * -La chiave sarà 'n', il secondo input della funzione.
 * -Il nodo precedente a 'p' è... nulla, poichò 'p' sarà il primo nodo della lista.
 * -Come successivo di 'p' usiamo la "vecchia" lista, che era identificata da 'a' (il suo primo nodo).
 *  Così abbiamo creato il nodo e siamo riusciti ad aggiungerlo in testa alla lista, but non è ancora abbastanza.
 *  Infatti, il nodo precedente di 'a' non è più NULL, perchè 'a' non è più il primo nodo.
 *  Dunque, se 'a' non è NULL (se la lista in input non era una lista vuota, ovvero non stiamo aggiungendo 'p' come primo nodo della lista), dobbiamo
 *  impostare 'p' come nodo precedente ad 'a'.
 *  Alla fine possiamo restituire 'p', il nuovo primo nodo che identifica la lista. */

struct node *append0(struct node *a, int n) {
	struct node *p = malloc(sizeof(struct node));
	p -> key = n;
	p -> prev = NULL;
	p -> succ = a;
	if(a != NULL) {
		a -> prev = p;
	}
	return p;
}

/* ENG:
 * In order to delete the first node of a list, the list must have one node at least, that's why we put the condition 'a != NULL'.
 * We must free the memory occupied by the node pointed by 'a', so we call the free fucntion from the stdlib header.
 * But first we need to save the value of 'a -> succ' into a variable, because we'd loose it after 'free(a)'.
 * 'p' ('a -> succ') is the new first node of the list, so it's previous node must be set to NULL, if 'p' is not NULL ('a' could be the only node of the input list).
 * ITA:
 * Per eliminare il primo nodo di una lista, la lista deve avere almeno un nodo, ecco perchè poniamo la condizione 'a != NULL'.
 * Dobbiamo prima liberare la memoria occupata dal nodo puntato da 'a', dunque chiamiamo la funzione free dell'intestazione stdlib.
 * Ma prima dobbiamo salvare il valore di 'a -> succ' in una variabile, perchè altrimenti lo perderemmo dopo 'free(a)'.
 * 'p' (a -> succ') è il nuovo primo nodo della lista, quindi il suo nodo precedente deve essere impostato a NULL, se 'p' non è NULL ('a' poteva essere l'univo nodo della lista in input). */

struct node *pop0(struct node *a) {
	struct node *p = NULL;
	if(a != NULL) {
		p = a -> succ;
		free(a);
		if(p != NULL) {
			p -> prev = NULL;
		}
	}
	return p;
}

/* ENG:
 * We said that there's NULL (no node) after the last node of the list. That's what will exploit to find the end of it while
 * we run a cycle to print its elements. We "increase" a pointer to node, by updating its value to point the next node each cycle, until
 * we find NULL.
 * ITA:
 * Abbiamo detto che dopo l'ultimo nodo della lista c'è NULL (nessun nodo). E' proprio ciò che sfrutteremo per trovare la fune di essa mentre
 * eseguiamo un ciclo per stampare i suoi elementi. "Incrementiamo" un puntatore a nodo aggiornando il suo valore per puntare al nodo successivo
 * ad ogni ciclo, finchè non troviamo NULL. */

void printList(struct node *a) {
	for(; a != NULL; a = a -> succ) {
		printf("%d\n", a -> key);
	}
}
