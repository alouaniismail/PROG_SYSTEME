#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
//#include<fcntl.h>

int main(void)
{
    int status;
    int arr[100000]={1,2,3};
    switch(fork()) {
    case -1:
        perror("parent: échec lors du fork\n");
        return EXIT_FAILURE;
    case 0:
      //apres la modif., le wait reprend l'execution du processus fils
        sleep(3);
	//cela veut dire qu'il s'endort pendant 3 secondes
	//avant de faire le boulot.
        printf("fils: arr[1]=%d\n",arr[1]); // affiche arr[1]=2
	//Le fils attend trois secondes pour être sûr que le père a bien changé la valeur et affiche l'élément du tableau. Le résultat est arr[1]=2, car chaque processus dispose de son propre espace mémoire. Tout se passe comme si le noyau dupliquait la mémoire lors d'un fork.
	//la pile ou est stockée ou le segment donné en quelque sorte est dupliqué pour chacun.
        break;
    default:
        arr[1]=200;
        wait(&status);
        break;
    }
    return EXIT_SUCCESS;
}

