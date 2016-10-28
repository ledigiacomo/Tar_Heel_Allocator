#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{
	int i;
	for(i = 0; i < 10000; i++)
	{
		int* toPrint = malloc(sizeof(int));
		toPrint = i;
		printf("%d\n", toPrint);
	}

	return (errno);
}