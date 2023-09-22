#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
}
thread_arg;

int var;
pthread_mutex_t mutex;

void* thread(void* vargp);

int main(){
    int i;

    int n_threads = 50;
    pthread_t t_id[n_threads];
    thread_arg a[n_threads];

    var = 0;
    pthread_mutex_init(&mutex, NULL);

    for(i = 0; i < n_threads; i++){
        a[i].id = i;
        pthread_create(&t_id[i], NULL, thread, (void*) &a[i]);
    }

    for(i = 0; i < n_threads; i++){
        pthread_join(t_id[i], NULL);
    }

    printf("Valor de var no fim do programa: %d\n", var);

    pthread_mutex_destroy(&mutex);
    pthread_exit((void*) NULL);
}

void* thread(void* vargp){
    int j;
    thread_arg* a = (thread_arg* ) vargp;

    pthread_mutex_lock(&mutex);
    printf("Thread %d: valor de var antes da conta: %d\n", a->id + 1, var);
    for(j = 0; j < 1000; j++){
        var += 1;
    }
    printf("Thread %d: valor de var depois da conta: %d\n", a->id + 1, var);

    pthread_mutex_unlock(&mutex);
    pthread_exit((void*) NULL);
}