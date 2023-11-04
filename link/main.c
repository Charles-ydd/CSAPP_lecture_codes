#include <stdio.h> 

int sum(int *a, int n);

int array[2] = {1, 2};

void  main() {
    int val = sum(array, 2);
    printf("%d \n", val);
}
