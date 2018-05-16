#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 3
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void *multitask(void *threadid)
{
	long tid = (long)threadid;
	
	if (tid == 0)
	{
		system("ex.exe");
	}
	else if (tid == 1)
	{
		system("HW4.exe");
	}
	else if (tid == 2)
	{
		system("HW5.exe");
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for (t = 0; t < NUM_THREADS; t++)
	{
		printf("-------Thread #%ld------------", t);
		rc = pthread_create(&threads[t], NULL, multitask, (void *)t);
		if (rc) 
		{
			printf("ERROR : return code from pthread_create() is %d\n", rc);
			exit(-1);	
		}
		
	}
	
	
	pthread_exit(NULL);
}
