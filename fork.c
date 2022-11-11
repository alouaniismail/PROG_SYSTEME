#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
  puts("Bonjour");
  fork();//2 processus pere et fils.
  puts("Au revoir");
  return EXIT_SUCCESS;
}
