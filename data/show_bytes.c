#include <stdio.h>
#include "string.h"
typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    // size_t: This type is used to represent the size of an object. Library functions that 
    //take or return sizes expect them to be of type or have the return type of size_t
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

int main() {
    show_int(12345);
    show_float(12345.0);
    show_int(1); // little endian
    const char* s  = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));
}