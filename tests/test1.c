#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{  
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

  return (errno);
}