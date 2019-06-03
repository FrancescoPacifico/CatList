#include "catList.h"

int main() {
	struct node *list = newList();
	int i;

	/* ENG:
	 * We create a list by calling append0 in a cycle. Appending items at the top of the list using a cycle will produce a list that contains those items
	 * in the reverse order.
	 * ITA:
	 * Creiamo una lista chiamando append0 in un ciclo. Aggiungere elementi in cima ad una lista usando un ciclo produrrà una lista che contiene tali elementi
	 * in ordine inverso. */

	for(i = 9; i >= 0; i--) {
		list = append0(list, i);
	}
	list = append(list, 10, 999);

	/* ENG:
	 * With the following instruction we pop the last node of the list by using listLen(list) - 1 as parameter.
	 * ITA:
	 * Con l'istruzione seguente elminiamo l'ultimo nodo della lista usando listLen(list) - 1 come prametro. */

	list = pop(list, listLen(list) - 1);
	printList(list);
	return 0;
}
