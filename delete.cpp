#include "setup.h"

void freeList(Node **head) {
	Node *temp = NULL;
	while(*head != NULL) {
		temp = *head;
		*head = temp->next;
		free(temp);
	}
}

void deleteAtHead(Node **head) {
	if (*head == NULL) {
		printf("Linked list empty!\n");
		return;
	}

	Node *temp = *head;
	*head = temp->next;
	free(temp);
}

void deleteAtTail(Node **head) {
	if (*head == NULL) {
		printf("Linked list empty!\n");
		return;
	}

	Node *temp = *head;
	if (temp->next == NULL) {
		free(*head);
		*head = NULL;
		return;
	}

	while(temp->next->next != NULL) {
		temp = temp->next;
	}


	free(temp->next);
	temp->next = NULL;
}

void deleteAtPosition(Node **head, int position){
	if (position == 1){
		deleteAtHead(&(*head));
		return;
	}
	
	Node *temp = *head;
	for (int i = 1; i < position - 1 && temp != NULL; ++i){
		temp = temp->next;
	}
	
	if(temp == NULL){
		printf("Position out of range!!\n");
		return;
	}
	
	Node *del = temp->next;
	temp->next = del->next;
	free(del);
}

void deleteAfterKeys(Node **head, int key){
	Node *temp = *head;
	if (temp == NULL) return;
	while(temp != NULL && temp->next != NULL){
		if(temp->data == key){
			Node *del = temp->next;
			temp->next = del->next;
			if (del->data != key){
				temp = temp->next;
			}
			free(del);
		} else {
			temp = temp->next;
		}
	}
}

void deleteBeforeKeys(Node **head, int key){
	if (*head == NULL || (*head)->next == NULL)
		return;
	
	while((*head)->next != NULL && (*head)->next->data == key)
		deleteAtHead(&(*head));

	Node *temp = *head;
	while(temp->next != NULL && temp->next->next != NULL){
		if (temp->next->next->data == key){
			Node *del = temp->next;
			temp->next = del->next;
			free(del);
		} else {
			temp = temp->next;
		}
	}
}

void deleteAllKeys(Node **head, int key){
	while (*head != NULL && (*head)->data == key){
		deleteAtHead(&(*head));
	}
	
	Node *temp = *head;
	while(temp!=NULL && temp->next != NULL){
		if (temp->next->data == key){
			Node *del = temp->next;
			temp->next = del->next;
			free(del);
		} else{
			temp = temp->next;
		}
	}
}

