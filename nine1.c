#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/stat.h>
#include<errno.h>
#include<assert.h>

extern int errno;

void readfile(const char* pathname, int count, char* buf){
  int fd,byte,length=count;
  fd=open(pathname,O_RDONLY);
  if(fd==-1){
    perror("open failed.");
    exit(1);
  }
  int i=0;
  /*read count bytes from the file*/
  while((byte=read(fd,buf,length))!=0){
    if(byte==-1){
      perror("read failed.");
      exit(1);
    }
    length=length-byte;
    buf=buf+length;
    i++;
  }
  assert(i==1);//mieux car avec printf, il faut remonter
  //pour verifier si c'est la bonne valeur de variable.
  /* printf("%d\n",i);*/
  close(fd);
  //en gros on lit count soit 256 octets (256 caracteres) on les met dans
  //buf et on continue cette fois avec length-byte(retour) a lire
  //puis on les met dans buf+length(ce qu'on a lu).
}


int main(void){
  char buffer[12878];//2^8 par défaut.(depuis ls -l resume_test.txt)
  //pas de malloc, le conteneur.
  //puis un read..
  //dans readfile, on l'ouvre puis read puis on le ferme
  //pour le read on fait ceci:
  //while((byte=read(fd,buf,length)!=0))
  //faire:
  //(lire les 12878 octets et les mettre dans buffer de meme capacite ici)
  //si byte est 0 cad. fin du fichier
  //sinon -1 error
  //sinon:
  //on a lu byte octets
  //la prochaine fois on doit lire ce qui reste soit: length-byte
  //et les mettre dans buffer+length.
  //la prochaine fois il va pouvoir lire 12878-12878 soit 0 et les mettre
  //a la fin du buffer(buffer+12878(length===byte)) => sortie de le boucle
  //en 1 tour, cela est fait.
  readfile("resume_test.txt",12878,buffer);
  printf("%s\n",buffer);//affiche le fichier avec un retour chariot.
  return 0;
}

  
