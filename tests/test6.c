#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{
  char* x = malloc(5);
  printf("Hello %p\n", x);
  x = "S";
  printf("x is: %s\n", x);

  free(x);
  printf("Goodbye %p\n", x);
  printf("x is: %s\n", x);

  return (errno);
}