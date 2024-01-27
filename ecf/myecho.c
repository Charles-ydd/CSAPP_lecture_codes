# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

int main(int argc, char *argv[], char *envp[]) {
    /* the prototype is int main(int argc, char *argv[], char *envp[])*/

    /* start code set the stack and pass the control 
    infomation(argvs and envps) to the new main function. */
    printf("Command-ine arguments:\n");
    for(int i = 0; argv[i] != NULL; i++) {
        printf("argv[%2d] : %s\n", i, argv[i]);
    }
    printf("Environment variables:\n");
    for(int i = 0; envp[i] !=NULL; i++) {
        printf("envp[%2d] : %s\n", i, envp[i]);
    }
}