# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>


pid_t Fork(void) {
    pid_t pid;

    if((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(0);
    }
}

int main() {
    pid_t pid;

    /* child sleeps until SIGKIL signal received, then dies */
    if ((pid = Fork()) == 0) {
        pause(); /* Wait for a signal to arrive */
        printf("control should never reach here!\n");
        exit(0);
    }

    /* parent sends a SIGKILL signal to a child */
    printf("%d\n", pid);
    kill(pid, SIGKILL);
    exit(0);
}