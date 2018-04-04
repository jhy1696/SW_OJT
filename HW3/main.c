#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

int main(void)
{
	FILE * textFile = fopen("program.txt","r");
	Container *cont = newContainer(textFile);
	scanLinkedList(cont, textFile);
	printLinkedList(cont->head);
    return 0;
}
