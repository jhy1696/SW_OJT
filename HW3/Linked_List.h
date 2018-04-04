#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct node
{
	char line[100];
	struct node * next;
} Node;

typedef struct LinkedListContainer
{
	Node *head;
	Node *tail;
} Container;

void scanLinkedList(Container *cont, FILE *textFile);
void printLinkedList(Node *head);
Container * newContainer(FILE *textFile);

#endif
