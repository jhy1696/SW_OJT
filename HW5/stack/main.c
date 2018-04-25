#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List.h"
#include "stack.h"
int main(int argc, char *argv[])
{
	FILE * textFile = fopen("program.txt","r");
	Container *cont = newContainer(textFile);
	push(cont, textFile);
	push(cont, textFile);
	push(cont, textFile);
	printLinkedList(cont->head);
	printf("\n");
	
	pop(cont);
	pop(cont);
	push(cont, textFile);
	
	printf("\nresult : \n");
	
	printLinkedList(cont->head);
	
	return 0;
}
