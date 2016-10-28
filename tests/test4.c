#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{
	int i;
	for(i = 32; i < 2050; i++)
	{
		void* num = malloc(i);
		//num = i;
		printf("%p\n", num);
	}
}