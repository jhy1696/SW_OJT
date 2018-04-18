#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE * textFile = fopen("program.txt","r");
	Container *cont = newContainer(textFile);
	scanLinkedList(cont, textFile);
	printLinkedList(cont->head);
	printf("\n");
	BubbleSort(cont);
	printLinkedList(cont->head);
	printf("\n");
	printLinkedList_Reverse(cont->head, cont->tail->next);
	return 0;
}
