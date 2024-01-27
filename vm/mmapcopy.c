#include "../include/csapp.h"
#include <unistd.h>
#include <sys/mman.h>

void mmapcopy(int fd, size_t length) {
    void* bufp = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0);
    write(1, bufp, length); // redirection to stdout.
    return;
}

int main(int argc, char* argv[]) {

    /*check for required command-line argument. */
    if (!(argc == 2)) {
        printf("%s\n", "only redirect the first file to stdout!");
    }
    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY, 0);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    struct stat file_info;
    
    if (fstat(fd, &file_info) == -1) {
        perror("Error getting file information");
        close(fd);
        return 1;
    }
    off_t file_size = file_info.st_size;
    mmapcopy(fd, file_size);
    close(fd);
    
}