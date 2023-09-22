#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
}
thread_arg;

void* thread(void* vargp);

int main(){
    int i;

    pthread_t t_id[2];
    thread_arg a[2];
    int n_threads = 2;

    for(i = 0; i < n_threads; i++){
        pthread_create(&t_id[i], NULL, thread, (void*) &(a[i]));
    }

    for(i = 0; i < n_threads; i++){
        pthread_join(t_id[i], NULL);
    }
    pthread_exit((void*) NULL);
}

void* thread(void* vargp){
    int i;

    thread_arg* a = (thread_arg*) vargp;

    printf("Thread %d began\n", a->id);

    // Workload
    int r = rand() % 2000000; // 2 million
    for (i = 0; i < r; i++);

    printf("Thread %d finished\n", a->id);

    pthread_exit((void*) NULL);
}