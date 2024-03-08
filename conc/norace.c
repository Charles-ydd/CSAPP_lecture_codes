#include "../include/csapp.h"
#define N 8

void* thread(void *varap);

int main(){
    pthread_t tid[N];
    int i, *ptr;

    for(i = 0; i <N; i++){
        ptr = malloc(sizeof(int));
        *ptr = i;
        pthread_create(&tid[i], NULL, thread, ptr);
    }
    for(i = 0; i < N; i++){
        pthread_join(tid[i], NULL);
    }
    exit(0);
}

/* thread routine */
void* thread(void* vargp){
    int myid = *((int*)vargp);
    free(vargp);
    printf("hello from thread %d\n", myid);
    return NULL;
}