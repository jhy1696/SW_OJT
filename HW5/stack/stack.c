#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List.h"
#include "stack.h"

void push(Container *cont, FILE *textFile)
{
	Node *tmp = (Node *) calloc(1, sizeof(Node));
	fgets(tmp->line, BUF, textFile);
	tmp->next = cont->head;
	cont->head = tmp;	
}

void pop(Container *cont)
{
	Node *tmp = cont->head->next;
	printf("POP : %s", cont->head->line);	
	free(cont->head);
	cont->head = tmp;
}
