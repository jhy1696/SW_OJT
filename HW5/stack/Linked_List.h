#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#define BUF 256


typedef struct node
{
	char line[BUF];
	struct node *next;
} Node;

typedef struct LinkedListContainer
{
	Node *head;
	Node *tail;
} Container;

void scanLinkedList(Container *cont, FILE *textFile);
void printLinkedList(Node *head);
void printLinkedList_Reverse(Node *head, Node *tail);
Container * newContainer(FILE *textFile);
void LinkedList_Swap(Node *A, Node *B);
void BubbleSort(Container *cont);



#endif
