#include "setup.h"

Node *createNode(int data) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Create node error!");
		exit(1);
	}

	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertAtHead(Node **head, int data) {
	Node *newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

void insertAtTail(Node **head, int data) {
	Node *newNode = createNode(data);
	if (*head == NULL) {
		*head = newNode;
		return;
	}

	Node *temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertAtPosition(Node **head, int data, int position) {
	if (position == 1) {
		insertAtHead(&(*head), data);
		return;
	}

	Node *temp = *head;
	for(int i = 1; i < position - 1 && temp != NULL; ++i) {
		temp = temp->next;
	}

	if(temp == NULL) {
		printf("insertAtPosition!!\n");
		return;
	}

	Node *newNode = createNode(data);
	newNode->next = temp->next;
	temp->next = newNode;
}

void insertAfterKeys(Node **head, int value, int key) {
	Node *temp = *head;
	while(temp != NULL) {
		if (temp->data == key) {
			Node *newNode = createNode(value);
			newNode->next = temp->next;
			temp->next = newNode;
			temp = temp->next;
		}
		temp = temp->next;
	}
}

void insertBeforeKeys(Node **head, int value, int key){
	Node *temp = *head;
	if (temp == NULL){
		return;
	}

	if (temp->data == key){
		insertAtHead(&(*head), value);
	}

	while (temp->next != NULL){
		if (temp->next->data == key){
			Node *newNode = createNode(value);
			newNode->next = temp->next;
			temp->next = newNode;
			temp = temp->next;
		}
		temp = temp->next;
	}
}

void printList(Node *head) {
	Node *temp = head;
	while(temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
