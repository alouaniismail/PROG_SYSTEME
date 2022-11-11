#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main (int argc, char* argv[])
{
  //int zero = 0;
  char* buffer="a";
  const int megabyte = 1024 * 1024;
  //1024=2**10.
  
  char* filename = argv[1];
  size_t length = (size_t) atoi (argv[2]) * megabyte;
  //2**30 au total de l'ordre du Gigaoctet.
  
  /* Ouvre un nouveau fichier. */
  int fd = open (filename, O_WRONLY | O_CREAT | O_EXCL, 0666);
  //les dernieres ressemblent a des permissions
  //en execution(cat autorisé) et en écriture/création unique uniquement.
  
  /* Se place un octet avant la fin désirée du fichier. */
  lseek (fd, length-1, SEEK_SET);
  /* Écrit un octet nul('a' en ACSII) à 63 modulo près. */
  write (fd, buffer  , 1);
  /* Terminé. */
  close (fd);
  //int close(int fd) prototype fonctionnel ( --).///
  return 0;
}
