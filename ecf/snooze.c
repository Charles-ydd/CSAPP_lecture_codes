# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>


/* homework 8.5 */
unsigned int snooze(unsigned int secs) {
    unsigned int N = sleep(secs);
    printf("Slept for %d of %d secs.", secs - N, secs);
    return N;
}