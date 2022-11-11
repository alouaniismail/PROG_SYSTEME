#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/stat.h>

char info[50];

int main() {
    int fdr;
    int rc = mknod("testfile",0777, (dev_t) 0);
    //Le 2ieme argument pour un fichier normal:
    //S_IFREG|S_IRUSR|S_IXUSR.
    if(rc<0) {
        perror("Error in mnod");
    }
    //si rc<0 cad. a 99% des cas: fichier deja existant
    //ajout de : file exists.
    fdr=open("testfile",O_RDONLY|O_WRONLY,0777);
    const char* buffer="abcde";
    write(fdr,buffer,strlen(buffer));
    read(fdr,info,50);//pas prise en considération lors du printf
    //en premier coup(vu avant.)./////////
    //ssize_t read(int fd, void* buf, size_t count);
    //important a rappeler chaque fois.
    printf("\n Received message=%s",info);
    printf("\n");
} 
