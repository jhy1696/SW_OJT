#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

#define BUF 256

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
