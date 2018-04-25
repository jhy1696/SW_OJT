#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List.h"

void scanLinkedList(Container *con, FILE *textFile)
{
	char line[BUF];
	Node *tmp, *tmp_tail = con->tail;
	while (!feof(textFile)) {
		tmp = (Node *) calloc(1, sizeof(Node));
		fgets(tmp->line, BUF, textFile);
		tmp->next = NULL;
		con->tail->next = tmp;
		con->tail = tmp;
		//printf("%s",tmp->line);
	}
	//return tmp;
}

void printLinkedList(Node *head)
{
	Node *tmp = head;
	while(tmp){
		printf("%s",tmp->line);
		tmp = tmp->next;
	}
}

void printLinkedList_Reverse(Node *head, Node *tail)
{
	Node *tmp;
	for (tmp = head; tmp != tail; tmp = tmp->next) {
		if (tmp->next == tail) {
			printf("%s",tmp->line);
			printLinkedList_Reverse(head, tmp);
		}
	}
}

Container * newContainer(FILE *textFile)
{
	Container *tmpCont = (Container *) calloc(1, sizeof(Container));
	Node *tmpNode = (Node *) calloc(1, sizeof(Node));
	//char line[256];
	tmpNode->next = NULL;
	tmpCont->head = tmpNode;
	tmpCont->tail = tmpNode;
	if (fgets(tmpNode->line, BUF, textFile)) {
		return tmpCont;
	}
	else {
		char empty[6] = "empty\0";
		for (int i = 0; i < 6; i++){
			tmpNode->line[i] = empty[i];
		}
		printf("error : empty text file\n");
		
		return tmpCont;
	}
	return tmpCont;
}

void LinkedList_Swap(Node *A, Node *B)
{
	char tmp[BUF];
	strncpy(tmp, B->line, BUF);
	strncpy(B->line, A->line, BUF);
	strncpy(A->line, tmp, BUF);
}

void BubbleSort(Container *cont)
{
	Node *tmp_i, *tmp_j;
	for (tmp_i = cont->head; tmp_i != NULL; tmp_i = tmp_i->next) {
		for (tmp_j = tmp_i; tmp_j != NULL; tmp_j = tmp_j->next) {
			if (tmp_i->line[0] > tmp_j->line[0]) {
				LinkedList_Swap(tmp_i, tmp_j);
			}
		}
	}
}





