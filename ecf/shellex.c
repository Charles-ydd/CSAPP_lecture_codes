#include "../include/csapp.h"
#define MAXARGS 128

/*Function prototypes*/
void eval(char *cmdline);
int parseline(char *buf, char **argv);

int main() {
    char cmdline[MAXLINE];

    while (1){
        printf("> ");
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin)) exit(0);
        /*int feof(FILE *stream)* tests the end-of-file indicator for the given stream. */
    }
}

/* eval - Evaluate a command line */
void eval(char *cmdline) {
    char *argv[MAXARGS];
    char buf[MAXLINE];
    int bg; 
}