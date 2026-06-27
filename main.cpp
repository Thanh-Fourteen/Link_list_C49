#include "insert.cpp"
#include "delete.cpp"

int main() {
	Node *header = NULL;
	insertAtHead(&header, 1);
	insertAtHead(&header, 1);
	insertAtHead(&header, 1);
	insertAtHead(&header, 1);
	printList(header);
	insertBeforeKeys(&header, 2, 1);
	printList(header);
	deleteBeforeKeys(&header, 1);
	printList(header);				// 1->NULL
	insertAtHead(&header, 2);
	printList(header);				// 1->NULL
	deleteBeforeKeys(&header, 1);
	printList(header);				// 1->NULL
	freeList(&header);
}














