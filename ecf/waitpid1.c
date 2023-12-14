# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

#define N 2


void unix_error(char *msg) {
    fprintf(stderr, "%s : %s\n", msg, strerror(errno));
    exit(0);
}


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
    int status, i;

    /* Parent creates N children */
    for(i = 0; i < N; i++) {
        if ((pid = Fork()) == 0) {
            exit(100 + i);
        } 

            
    }

    /* parent reaps N children in no particular order */
    while ((pid = waitpid(-1, &status, 0) > 0)) {
        if (WIFEXITED(status))
            printf("child %d terminated normally with exit status=%d\n", 
                    pid, WEXITSTATUS(status));
            // WEXITSTATUS return a status of a normally terminated process.
        else 
            printf("child %d terminated abnormally\n", pid);

        /* the only normal termination is if there are no more children. */
        if (errno != ECHILD) {
            unix_error("waitpid error!");
        }
    }
}