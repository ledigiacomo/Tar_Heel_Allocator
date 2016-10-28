#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{
	int i;
	int* prevPrint = malloc(sizeof(int*));
	for(i = 0; i < 10; i++)
	{
		int* toPrint = malloc(sizeof(int*));
		toPrint = i;
		printf("%p\n", toPrint);
		if(prevPrint)
			printf("Difference: %d\n", (&prevPrint - &toPrint));
		prevPrint = toPrint;
	}

	return (errno);
}