#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
  int fd1,
    fd2,
    fd3;
  fd1=open("test",O_CREAT|O_RDWR,0644);
  //int open(const char* path, int flags,...) (si non existence, création)
  //0644 a retenir..
  if(fd1==-1)
    {
      perror("open");
      exit(1);
    }
  printf("fd1=%d\n",fd1);
  //ssize_t write(int fd, const void* buffer, size_t count)
  //comme avant(pas de nouvelle chose).
  write(fd1,"hello",6);
  fd2=dup(fd1);//fd1 et fd2 sont associées au fichier test.
  printf("fd2=%d\n",fd2);
  write(fd2,"wor",3);
  close(0);//on ferme le fichier dont le descripteur est 0.
  fd3=dup(fd1);//fd3 et fd1 sont associés au fichier test.
  printf("fd3=%d\n",fd3);//recuperation,presque..(rslt)
  write(0,"ld",2);
  dup2(3,2);
  //remplace le fichier pointe par le descripteur 3 celui dont le descripteur
  //est 2.
  write(2,"!\n",2);
  return 0;
}
