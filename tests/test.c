#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{  
  //test1
  printf("Test1:\n");
  void *z = malloc(512);
  char *y = malloc(70);
  void *x = malloc(4097);
  char *w = malloc(0);
  void *v = malloc(2049);
  void *u = malloc(-3);
  char *t = malloc(sizeof(char));
  t[0] ='j';
  y = "Y";
  w = "W";
  printf("Hello %p\n", z);
  printf("Hello %p\n", y);
  printf("Should fail: Too big %p\n", x);
  printf("Malloced 0 %p\nValue: %s\n", w, w);
  printf("Hello %p\n", v);
  printf("Should fail: negative # %p\n", u);
  printf("Hello %s\n", t);
  printf("Pass Test1\n\n");

  //test2
  printf("Test 2:\n");
  char *s = malloc(513);
  char *r = malloc(70);
  char *q = malloc(0);
  
  s = "Z\0";
  r = "Y";
  q = "W";
  printf("Hello %p\nValue: %s\n", s, s);
  printf("Hello %p\nValue: %s\n", r, r);
  printf("Malloced 0 %p\nValue: %s\n", q, q);
  printf("Hello %s\n", t);
  printf("Pass Test 2\n\n");

  //test3 malloc a large number of objects
  printf("Test 3:\n");
  int i;
  for(i = 0; i < 1000; i++)
  {
    int* toPnt = malloc(sizeof(int));
  }
  printf("Pass Test 3\n\n");

  //test4 malloc different sizes
  printf("Test 4:\n");
  for(i = 32; i < 2050; i++)
  {
    void* num = malloc(i);
  }
  printf("Pass Test 4\n\n");

  //test 5: see if memory is allocated sequentially
  printf("Test 5:\n");
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
  printf("Pass Test 5\n\n");

  //test 6: basic free test
  printf("Test 6:\n");
  void* f = malloc(5);
  printf("Hello %p\n", f);
  free(f);
  printf("Goodbye %p\n", f);
  printf("Pass Test 6\n\n");

  //test 7: check contents after free (poison test)
  printf("Test 7:\n");
  int* g = malloc(80);
  printf("Hello %p\n", *g);
  *g = 8;

  free(g);
  printf("Goodbye %p\n", g);
  printf("g is: %p\n", *(g+8));
  printf("Pass Test 7\n\n");

  //test 8: Allocate and Free a large number of objects
  printf("Test 8:\n");
  char* ptrs[200];
  for(i = 0; i < 100; i++)
  {
    char* h = malloc(500);
    ptrs[i] = h;
  }

  for(i = 0; i < 100; i++)
  {
    free(ptrs[i]);
  }
  printf("Pass Test 8\n\n");

  //test 9: malloc free and malloc again
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