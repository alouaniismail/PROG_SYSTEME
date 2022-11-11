#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
//#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/stat.h>
#include<errno.h>
#include<assert.h>
#include<dirent.h>

int main(int argc, char** argv, char** envp){
  DIR* pDIR=opendir(".");
  if(pDIR==NULL){
    perror("opendir() failed");
    exit(-1);
  }
  struct dirent* pDirEnt=readdir(pDIR);
  while(pDirEnt != NULL){
    printf("%s\n",pDirEnt->d_name);
    pDirEnt=readdir(pDIR);
  }
  closedir(pDIR);
}

/*
A retenir dans dirent.h :
DIR* opendir(const char* name)
et contient des struct dirent via:
struct dirent* readdir(DIR* dir);
et on le ferme apres manipulations via:
int closedir(DIR* dir);
*/

/*
la struct dirent est via 5 champs:
ino_t d_ino numero de l'inode
off_t d_off decalage vers le prochain dirent
unisgned short d_reclen longueur de cet enregistrement
unsigned char d_type type du fichier
char d_name[256] nom du fichier
*/

/*
VOILA se termine donc les 3 premieres parties:
intro
appels systemes
fichiers
*/
