#ifndef SETUP_H
#define SETUP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *createNode(int data);

void insertAtHead(Node **head, int data);
void insertAtTail(Node **head, int data);
void insertAtPosition(Node **head, int data, int position);
void insertAfterKeys(Node **head, int value, int key);
void insertBeforeKeys(Node **head, int value, int key);


void printList(Node *head);
void freeList(Node **head);
void loadTestCase(Node **head, const char *file_path);

void deleteAtHead(Node **head);
void deleteAtTail(Node **head);
void deleteAtPosition(Node **head, int position);
void deleteAfterKeys(Node **head, int key);
void deleteBeforeKeys(Node **head, int key);
void deleteAllKeys(Node **head, int key);

#endif
