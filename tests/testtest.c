#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{ 
  int i;
    char* ptrs[200];

  printf("Test 9:\n");
  printf("beg loop1");
  fflush(stdout);
  for(i = 0; i < 100; i++)
  {
    char* h = malloc(500);
    ptrs[i] = h;
  }
  printf("fin loop1");
  fflush(stdout);

  for(i = 0; i < 100; i++)
  {
    free(ptrs[i]);
  }
  printf("fin loop2");
  fflush(stdout);

  for(i = 0; i < 100; i++)
  {
    char* h = malloc(500);
    ptrs[i] = h;
  }
  printf("Pass Test 9\n\n");

  //test 10: malloc and free aand malloc again a large number of objects from the middle
  printf("Test 10\n");
  int* pointers[2100];
  for(i = 0; i < 2000; i++)
  {
    pointers[i] = malloc(80);
  }

  for(i = 0; i < 50; i++)
  {
    free(pointers[i+120]);
  }

  for(i = 0; i < 100; i++)
  {
    pointers[i+1999] = malloc(80);
  }

  printf("Pass Test 10\n\n");
  printf("All tests passed\n");

  return (errno);
}