#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void sig_handler(int s) {
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++){
            write(1, "*", 1);
            
            sleep(1);
        }
        write(1, "\n", 1);
    }
    exit(0);
}

int main() {
    sigset_t mask_one, prev;

    signal(SIGINT, sig_handler);

    sigemptyset(&mask_one);
    sigaddset(&mask_one, SIGINT);

    sigprocmask(SIG_BLOCK, &mask_one, &prev);
    write(1, "Block SIGINT!", strlen("Block SIGINT!"));
    write(1, "\n", 1);
    // If send ctrl+c between BLOCK and SETMASK, the sig_handler function will
    // be called. Mantion that exit(0) in the sig_handler. Therefore, Unblock 
    // SIGINT does not appear in the screen. 
    for(int i = 0; i < 20; i++) sleep(1);
    sigprocmask(SIG_SETMASK, &prev, NULL);
    write(1, "Unblock SIGINT!", strlen("Unblock SIGINT!"));
    write(1, "\n", 1);
    while(1);
}