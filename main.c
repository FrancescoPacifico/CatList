#include "catList.h"

int main() {
	struct node *list = newList();
	int i;
	for(i = 0; i < 10; i++) {
		list = append0(list, i);
	}
	printList(list);
	return 0;
}
