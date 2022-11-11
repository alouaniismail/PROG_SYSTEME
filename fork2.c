#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
  int status;
  puts("parent seulement");
  switch(fork()){
  case -1:
    perror("parent: echec lors du fork.\n");
    return EXIT_FAILURE;
  case 0://code du fils(ce processus mais clone)
    printf("fils: effectue la moitie de la tache.\n");
    return EXIT_SUCCESS;
  default://code du parent(ce processus)
    printf("parent: effectue la moitie de la tache.\n");
    wait(&status);
    //attendre le processus fils qu'il soit fini.
    //afficher en sorte l'execution de ce processus en memoire.
    //pid_t wait(int *status_pointer).
    break;
  }
  puts("parent seulement");
  return EXIT_SUCCESS;
}
