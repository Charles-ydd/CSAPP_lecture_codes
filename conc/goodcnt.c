#include "../include/csapp.h"

void* thread(void *vargp);

/* global shared variable */
volatile long cnt = 0;
sem_t mutex;
/* 在本次线程内, 当读取一个变量时，编译器优化时有时会先把变量读取到一个寄存器中；以后，
再取变量值时，就直接从寄存器中取值；当内存变量或寄存器变量在因别的线程等而改变了值，
该寄存器的值不会相应改变，从而造成应用程序读取的值和实际的变量值不一致*/

int main(int argc, char **argv) {
    long niters;
    pthread_t tid1, tid2;

    /* check input argument */
    if(argc != 2) {
        printf("usage: %s <niters>", argv[0]);
        exit(0);
    }

    niters = atoi(argv[1]);
    sem_init(&mutex, 0, 1);
    /* create threads and wait for them to finish. */
    pthread_create(&tid1, NULL, thread, &niters);
    pthread_create(&tid2, NULL, thread, &niters);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("cnt is %ld \n", cnt);

}

void* thread(void *vargp){
    long i = 0;
    long n = *((long*)vargp);

    for (i = 0; i < n; i++){
        sem_wait(&mutex);
        cnt++;
        sem_post(&mutex);
    }
}
