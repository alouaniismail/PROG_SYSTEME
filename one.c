#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(void){
  struct stat buffer;
  int fd=open("test",O_CREAT|O_RDWR,0644);
  int state=stat("test",&buffer);
  printf("retour = %d\n",state);//0 si pas d'erreur, -1 sinon.
  printf("fd = %d\n",fd);//3 comme on a dit avant sur dup/dup2.
  printf("Numéro i-noeud = %ld\n",buffer.st_ino);
  //long par %d uniquement.
  printf("Nombre de liens matèriels = %ld\n",buffer.st_nlink);
  printf("Taille totale en octets = %ld\n",buffer.st_size);
  write(fd,"Hello world!\n",14);
  printf("Taille totale en octets = %ld\n",buffer.st_size);
  //C'est juste à la fin du processus (./a.out --execution) ou s'est vraiment
  //pris en compte.(et apres(persistance))
  printf("fichier normal ? %d\n",S_ISREG(buffer.st_mode));
  printf("fichier de type lien symbolique ? %d\n",S_ISLNK(buffer.st_mode));
  printf("fichier socket ? %d\n",S_ISSOCK(buffer.st_mode));
  printf("fichier device (type caractere) ? %d\n",S_ISCHR(buffer.st_mode));
  printf("fichier device (type bloc) ? %d\n",S_ISBLK(buffer.st_mode));
  printf("fichier fifo ? %d\n",S_ISFIFO(buffer.st_mode));
  FILE* f=fopen("test","rw+");
  printf("%d\n",fileno(f));//donne 4(nouvelle ouverture) normalement 3.
  int fd2=open("test",O_RDWR,0644);
  printf("%d\n",fd2);//donne 5, c'est normal vu le continu
  //de CETTE opération.(Mais il faut utiliser(c'est serree) le fd d'origine)
  write(5,"Nooo",5);
  write(5," Yesss!",7);
  //depuis le début(offset disposé à NULL au tout début.).
  fclose(f);
  return 0;
}
