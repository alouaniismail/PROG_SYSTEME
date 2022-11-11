#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    char mode[] = "0777";
    //sans specifier la taille 0777 les permissions comme le type mode_t.
    char buf[100] = "resume_test.txt";
    //le fichier 100 caracteres dans un nom c'est suffisant.
    int i;
    i = strtol(mode, 0, 8);
    //traduire en octal dont la fin est 0 dans la chaine (char**)
    //le mode de type char[].
    printf("%d\n",i);//511(le top: TOUTES les permissions)
    printf("%d\n",chmod(buf,i));//0 car pas d'erreur.
    if (chmod (buf,i) < 0)
    {
        fprintf(stderr, "%s: error in chmod(%s, %s) - %d (%s)\n",
                argv[0], buf, mode, errno, strerror(errno));
        exit(1);
    }
    //retenir le strerror comme perror jointure naturelle avec errno..///
    return(0);
}
