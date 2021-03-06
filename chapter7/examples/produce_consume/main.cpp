#include <iostream>
#include <pthread.h>

#define MAXNITEMS 100'000'000
#define MAXNTHREADS 100

int nitems;
struct {
    pthread_mutex_t mutex;
    int buff[MAXNITEMS];
    int nput;
    int nval;
} shared = {
PTHREAD_MUTEX_INITIALIZER
};

void *produce(void*), *consume(void*), consume_wait(int i);

int main() {
    int i, nthreads, count[MAXNTHREADS];
    pthread_t tid_produce[MAXNTHREADS], tid_consume;
    nitems      = MAXNITEMS;
    nthreads    = MAXNTHREADS;
    pthread_setconcurrency(nthreads+1);

    for (i = 0; i < nthreads; i++) {
        count[i] = 0;
        pthread_create(&tid_produce[i], NULL, produce, &count[i]);
    }
    pthread_create(&tid_consume, NULL, consume, NULL);

    for (i = 0; i < nthreads; i++) {
        pthread_join(tid_produce[i], NULL);
        printf("count[%d] = %d\n", i, count[i]);
    }
    pthread_join(tid_consume, NULL);

    auto result = 0;
    for (int i = 0; i < MAXNTHREADS; ++i)
        result += count[i];
    printf("result = %d\n", result);
    return 0;
}

void* produce(void* arg) {
    for (;;) {
        pthread_mutex_lock(&shared.mutex);
        if (shared.nput >= nitems) {
            pthread_mutex_unlock(&shared.mutex);
            return (NULL);
        }
        shared.buff[shared.nput] = shared.nval;
        shared.nput++;
        shared.nval++;
        pthread_mutex_unlock(&shared.mutex);
        *((int*) arg) += 1;
    }
}

void* consume(void* arg) {
    for (int i = 0; i < nitems; i++) {
        consume_wait(i);
        if (shared.buff[i] != i)
            printf("buff[%d] = %d\n", i, shared.buff[i]);
    }
    return (NULL);
}

void consume_wait(int i) {
    for (;;) {
        pthread_mutex_lock(&shared.mutex);
        if (i < shared.nput) {
            pthread_mutex_unlock(&shared.mutex);
            return;
        }
        pthread_mutex_unlock(&shared.mutex);
    }
}