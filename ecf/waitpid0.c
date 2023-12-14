# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>



/* Wrapping function */
pid_t Fork(void) {
    pid_t pid;

    if((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(0);
    }
}

int main() {
    pid_t pid, childpid;
    int status = 0;


    // pid in main is not zero, but zero in child process.
    pid = Fork();
    if (pid == 0) {
        /*child*/
        sleep(8);
        exit(0);  // child will be exited in this command.
    }
    else {
        printf("parent : x=%d\n", 1);
    }
    printf("pid:%d\n", pid);

    do {
        // don't block waiting
        childpid = waitpid(pid, &status, WNOHANG);
        if (childpid == 0) {
            printf("No child exited, ret = %d\n", childpid);
            sleep(1);
        }
    } while (childpid == 0);
    
    if (WIFEXITED(status))
        printf("normal exit: %d\n", childpid);
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGKILL)
        printf("killed by SIGKILL signal\n");
}