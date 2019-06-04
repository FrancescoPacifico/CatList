#include "catList.h"
#include "catList_s.h"

int main() {
	struct node *list = newList();
	struct node_s *list_s = newList_s();
	int i, n;

	/* ENG:
	 * This is an array of strings that we'll use to create a list of strings in the next for cycle.
	 * ITA:
	 * Questo è un array di stringhe che useremo per creare una lista di stringhe nel prossimo ciclo. */

	char *sample[] = {
		"!", "array", "an", "is", "this"
	};

	/* ENG: 
	 * We can dinamically calculate the nuber of elements of our 'sample' array by dividing its size for the size of one of its elements (pointer to char).
	 * ITA: 
	 * Possiamo calcolare dinamicamente il numero di elementi del nostro array 'sample' dividendo la sua dimensione per quella di uno dei suoi elementi (puntatore a char). */

	n = sizeof(sample) / sizeof(char *);

	/* ENG:
	 * We create a list by calling append0 in a cycle. Appending items at the top of the list using a cycle will produce a list that contains those items
	 * in the reverse order.
	 * ITA:
	 * Creiamo una lista chiamando append0 in un ciclo. Aggiungere elementi in cima ad una lista usando un ciclo produrrà una lista che contiene tali elementi
	 * in ordine inverso. */

	for(i = 0; i < n; i++) {
		list = append0(list, i);
		list_s = append0_s(list_s, sample[i]);
	}
	list = append(list, 3, 999);

	/* ENG:
	 * With the following instruction we pop the last node of the list by using listLen(list) - 1 as parameter.
	 * ITA:
	 * Con l'istruzione seguente elminiamo l'ultimo nodo della lista usando listLen(list) - 1 come prametro. */

	list = pop(list, listLen(list) - 1);
	printList(list);
	printList_s(list_s);
	return 0;
}
