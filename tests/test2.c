#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() 
{  
  char *z = malloc(513);
  char *y = malloc(70);
  char *w = malloc(0);
  
  z = "Z\0";
  y = "Y";
  w = "W";
  printf("Hello %p\nValue: %s\n", z, z);
  printf("Hello %p\nValue: %s\n", y, y);
  printf("Malloced 0 %p\nValue: %s\n", w, w);
  printf("Hello %s\n", t);

  return (errno);
}