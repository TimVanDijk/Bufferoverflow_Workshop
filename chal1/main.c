#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  volatile int target;
  char buf[32];

  target = 69;
  gets(buf);

  if(target != 69) {
      printf("Succes!\n");
  } else {
      printf("Nope :(\n");
  }
}

