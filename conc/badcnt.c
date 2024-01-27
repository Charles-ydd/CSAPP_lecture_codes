#include "../include/csapp.h"

void* thread(void *vargp);

/* global shared variable */
volatile long cnt = 0;
