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

/* ENG:
 * In the same way we can calculate the length of a list.
 * ITA:
 * Allo stesso modo possiamo calcolare la lunghezza di una lista. */

int listLen(struct node *a) {
	int i;
	for(i = 0; a != NULL; a = a -> succ, i++);
	return i;
}

/* ENG:
 * Now we have all the basic tools needed to manage a list, but it's always better to create more complex functions to make the job easier.
 * We can start by creating a function that adds a node in the second position of a list (index 1, because the first index is 0).
 * This will be very useful later.
 * ITA:
 * Ora abbiamo tutti gli strumenti di base necessari per gestire una lista, ma è sempre meglio creare funzioni più complesse per rendere il lavoro più facile.
 * Possiamo cominciare creando una funzione che aggiunge un nodo nella seconda posizione di una lista (indice 1, poichè il primo indice è 0).
 * Ciò sarà molto utile in seguito. */

/* ENG:
 * This function is very similar to append0: we create a node and assign the 'n' input key to it, then we set its previous node to 'a' (because 'a' is still the first node) and
 * its following node to 'a -> succ'(beacuase 'p' will be between 'a' and its following).
 * 'a -> succ' is no more the same as before, because we put 'p' in that position, so we must update 'a -> succ' to 'p'.
 * If 'a' was a list made of just one node, then 'a -> succ', before the update, was NULL, and so is 'p -> succ' now because it took its value;
 * so we must be careful and put the condition 'p -> succ != NULL' before updating its pointer to the previous node (that must be 'p').
 * ITA:
 * Questa funzione è molto simile ad append0: creiamo un nodo e assegnamo la chiave in input 'n' ad esso, poi impostiamo il suo nodo precedente ad 'a' (poichè 'a' è ancora il primo nodo) e
 * il suo successivo a 'a -> succ' (poichè 'p' sarà tra 'a' e il suo successivo).
 * 'a -> succ' non è lo stesso di prima, poichè abbiamo inserito 'p' in quella posizione, perciò dobbiamo aggiornare 'a -> succ' a 'p'.
 * Se 'a' era una lista fatta di un solo nodo, allora 'a -> succ', prima dell'aggiornamento, era NULL, e tale è ora 'p -> succ' perchè ha preso il suo valore;
 * quindi dobbiamo fare attenzione e porre la condizione 'p -> succ != NULL' prima di aggiornare il suo puntatore al nodo precedente (che dovrà essere 'p'). */

struct node *append1(struct node *a, int n) {
	struct node *p;
	if(a != NULL) {
		p = malloc(sizeof(struct node));
		p -> key = n;
		p -> prev = a;
		p -> succ = a -> succ;
		a -> succ = p;
		if(p -> succ != NULL) {
			p -> succ -> prev = p;
		}
	}
	return a;
}

/* ENG:
 * In the same way we can easily creaete a function that pops the node at index 1. We simply must remember to call the free function from stdlib and pay attenction to the
 * links between the nodes we are working on.
 * ITA:
 * Allo stesso modo possiamo facilmente creare una funzione che elimina il nodo all'indice 1. Dobbiamo semplicemente ricordare di chiamare la funzione free da stdlib e prestare
 * attenzione ai collegamenti tra i nodi su cui stiamo lavorando. */

struct node *pop1(struct node *a) {
	struct node *temp;
	if(a != NULL) {
		if(a -> succ != NULL) {
			temp = a -> succ;
			a -> succ = temp -> succ;
			if(temp -> succ != NULL) {
				temp -> succ -> prev = a;
			}
			free(temp);
		}
	}
	return a;
}

/* ENG:
 * It may be useful to have a function that takes a list and an integer that represents an index as input and return a pointer to the node at that index position in the list,
 * if it exists. Building it is very easy: we'll use the same structure of the prinList function, but this time we'll stop the cycle when we reach a certain index. So we need to count
 * how many cycles we do. To do it, we'll decrease the input index until it reaches 0 while we increase the pointer to node with 'a = a -> succ' (always using the condition 'a -> NULL', in
 * case an "out of range" index is given to the function).
 * ITA:
 * Può essere utile avere una funzione che prende in input una lista e un intero che rappresenta un indice e restituisce un puntatore al nodo nella posizione di quell'indice all'interno della lista,
 * se esiste. Costruirla è molto semplice: useremo la stessa struttura della funzione printList, ma questa volta fermeremo il ciclo quando raggiungiamo un certo indice. Dunzue abbiamo bisogno
 * di contare quanti cicli facciamo. Per farlo, diminuiremo l'indice in input finchè non ranggiunge 0 mentre incrementiamo il puntatore a nodo con 'a = a -> succ' (sempre ponendo la condizione
 * 'a != NULL, nel caso venga passato alla funzione un indice troppo grande). */

struct node *findIndex(struct node *a, int i) {
	for(;a != NULL && i > 0; a = a -> succ, i--);
	return a;
}

/* ENG:
 * Now that we have built these last three functions, we can use them to achieve something useful.
 * We've already said that a list in not more than a pointer to a node, so if we take pointer to a node in the middle of a list, we can consider it as another list (a sub-list).
 * So, if we reach that middle node, we can call the function appen1 or pop1 with no problem at all (not append0 and pop0, beacuase they only work if the previous node is NULL).
 * We'll now create two functions that use findIndex to reach a node in a list to add a node immediately after or pop the node immeditely after.
 * ITA:
 * Ora che abbiamo costruito queste ultime tre funzioni, possiamo usarle per ottenere qualcosa di utile.
 * Abbiamo già detto che una lista non è altro che un puntatore a un nodo, dunque se prendiamo un puntatore a un nodo nel mezzo della lista, possiamo considerarlo come un'altra lista (una sotto-lista).
 * Quindi, se raggiungiamo tale nodo, possiamo chiamare la funzione append1 o pop1 senza alcun problema (non append0 o pop0, perchè esse funzionano solo se il nodo precedente è NULL).
 * Ora costruiremo due funzioni che usano findIndex per raggiungere un nodo in una lista per aggiungere un nodo immediatamente dopo o per eliminare il nodo immediatamente dopo. */

struct node *append(struct node *a, int i, int n) {
	if(i <= 0) {
		return append0(a, n);
	}
	append1(findIndex(a, i - 1), n);
	return a;
}

struct node *pop(struct node *a, int i) {
	if(i <= 0) {
		return pop0(a);
	}
	pop1(findIndex(a, i - 1));
	return a;
}

/* ENG:
 * It's easy to calculate the cost of these functions in terms of time.
 * There are functions whose cost is not influenced by the length of the input list, like append0, append1, pop0 and pop1;
 * and other functions that necessarily have to check every node in the list, like printList and listLen; so... the more it's long the more it costs.
 * But there are also functions whose cost depends on another parameter. For example, in the findIndex function we make 'i' cycles and 'i' is given as input.
 * So, in this case we have to calculate the cost of the function in the worst case possible, that's 'i' = 'l', where 'l' is the length of the list.
 * ITA:
 * E' facile calcolare il costo di queste funzioni in termini di tempo.
 * Ci sono funzioni il cui costo non è influenzato dalla lunghezza della lista in input, come append0, append1, pop0 e pop1;
 * e altre funzioni che necessariamente devono controllare ogni nodo nella lista, come printList e listLen; dunque... più è lunga più costa.
 * Ma ci sono anche funczioni il cui costo dipende da un altro parametro. Per esempio, nella funzione findIndex eseguiamo 'i' cicli e 'i' è dato come input.
 * Dunque, in questo caso dobbiamo calcolare il costo della funzone nel caso peggiore possibile, che è 'i' = 'l', dove 'l' è la lunghezza della lista. */
