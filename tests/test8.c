#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{
	char* ptrs[200];
	int i;
	for(i = 0; i < 100; i++)
	{
		char* x = malloc(500);
		ptrs[i] = x;
	}

	for(i = 0; i < 100; i++)
	{
		free(ptrs[i]);
	}

	return (errno);
}