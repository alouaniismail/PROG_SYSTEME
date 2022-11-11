#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<string.h>

int main(void){
  int fflags,rVal,fd;
  if((fd=open("file1",O_CREAT|O_APPEND, S_IRWXU))<0){
    printf("error opening file.\n");
    exit(EXIT_FAILURE);
  } else {
    printf("file opened.\n");
  }

  if((rVal=fcntl(fd,F_GETFL))<0){
    printf("Error getting file status flags.\n");
    exit(EXIT_FAILURE);
  } else {
    printf("File status flags retrived.\n");
  }
  //O_ACCMODE has the value of three.
  fflags=rVal & O_ACCMODE;
  if(fflags == O_RDONLY){
    printf("File is ready only.\n");
  } else if (fflags == O_WRONLY){
    printf("File is write only.\n");
  } else if (fflags == O_RDWR) {
    printf("File is read / write.\n");
  } else {
    printf("No idea.\n");
  }

  if(close(fd)<0){
    printf("Error closing file.\n");
    exit(EXIT_FAILURE);
  } else {
    printf("File descriptor closed.\n");
  }

  return 0;
}
