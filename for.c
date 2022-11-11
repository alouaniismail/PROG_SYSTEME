#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<string.h>

int main(void){
  printf("duplicate an existing file descriptor (F_DUPFD) %d\n",F_DUPFD);
  int fd[2];
  char buf1[19]="Linux hint website";
  char buf2[19];
  fd[0]=open("sample.txt",O_RDWR);
  fd[1]=open("sample.txt",O_RDWR);
  //IL FAUT QU'IL EXISTE SINON ON AJOUTE O_CREAT!!
  write(fd[0],buf1,strlen(buf1));
  write(1,buf2,read(fd[1],buf2,19));
  //on ecrit en stdout buf2 de longueur
  //ce qu'on lit depuis fd[1] et on met dans buf2 toutes les 19 octets
  //en 1 seul fois.
  //il s'agit du même fichier où on peut ecrire et lire
  //donc si on fait un : write(1,buf2,read(fd[1],buf2,19)) on va ecrire
  //une donnee de longueur le retour de la lecture et la mise en buf2 de 19
  //octets de la même identification soit les 2 premiers arguments: 1,buf2.
  close(fd[0]);
  close(fd[1]);
  printf("\nSTDOUT_FILENO=%d\n\n",STDOUT_FILENO);
  return 0;
}
