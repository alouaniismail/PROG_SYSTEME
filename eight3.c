#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  
// Driver Code
int main(int argc, char* argv[])
{
    // Link function
    int l = link(argv[1], argv[2]);
  
    // argv[1] is existing file name
    // argv[2] is link file name
    if (l == 0) {
        printf("Hard Link created"
               " succuessfuly");
    }

    unlink(argv[2]);

    int l2=symlink(argv[1],argv[2]);

    if(l2==0){
      puts("Soft link created"
	   "successfully");
    }

    unlink(argv[2]);
    //toujours le premier existe rempli et le deuxieme n'existe meme pas.
  
    return 0;
}
