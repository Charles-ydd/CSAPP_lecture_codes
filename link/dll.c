#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int x[2] = {1, 2};
int y[2] = {3, 4};

int z[2];

int main() {
    void *handle;
    void (*addvec)(int *, int *, int *, int); // function pointer
    char *error;

    /* Dynamically load the shared library containing addvec()*/
    handle = dlopen("./libmyvector.so", RTLD_LAZY);
    if (!handle) {

        /* fprintf stream: This is a pointer to a FILE object, which represents 
        the file or output stream where the formatted data should be written.
         It can point to a file, the standard output (stdout), or other output 
         destinations
         */
        // stderr : standard error, it is typically not redirected to a file but
        // is displayed on the console or terminal.

        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    /* get a pointer to the addvec() function we just loaded */
    addvec = dlsym(handle, "addvec");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    addvec(x,y,z,2);
    printf("z = [%d, %d]\n", z[0], z[1]);

    /* unload the shared library */
    if (dlclose(handle) < 0) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    return 0;
}