# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>



/* Wrapping function */
pid_t Fork(void) {
    pid_t pid;

    if((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(0);
    }
}

int main() {
    pid_t pid;
    int x = 1;


    // pid in main is not zero, but zero in child process.
    if (Fork() == 0) {
        /*child*/
        printf("child : x=%d\n", ++x);
    }
    
    printf("parent : x=%d\n", --x);
    exit(0);
}