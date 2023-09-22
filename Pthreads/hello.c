#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

#define NUM_THREADS 30

void* PrintHello(void* thread_id){
    long t_id;
    t_id = (long) thread_id;

    printf("Hello world! I'm thread #%ld!\n", t_id);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    pthread_t threads[NUM_THREADS];

    int rc;

    long t;
    for (t = 0; t < NUM_THREADS; t++){
        printf("Estou no main: Criando a thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void* ) t);

        sleep(1);
        if (rc){
            printf("Error: returned code from pthread_create is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}