#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{
  int* x = malloc(5);
  printf("Hello %p\n", x);
  *x = 8;
  printf("x is: %d\n", *x);

  free(x);
  printf("Goodbye %p\n", x);
  printf("x is: %d\n", *x);

  return (errno);
}