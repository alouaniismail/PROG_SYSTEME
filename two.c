#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(void){
  int creation=creat("test",O_CREAT|O_APPEND);//existe aussi O_TRUNC
  //si fichier existe, vider le de son contenu.
  write(creation,"NO/YES.\n",8);
  //### avec open, le creat ne compte pas et prend en considération
  //les '\n'.
  //affiche le fichier en jaune avec des permissions elevees au debut(privilege
  //noyau de travailler tout seul et d'en extraire) et en vert apres
  //comme ''deja consulte'.
  return 0;
}
