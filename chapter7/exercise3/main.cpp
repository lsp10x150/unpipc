#include <iostream>
#include <pthread.h>

pthread_mutexattr_t mattr;
pthread_condattr_t cattr;

int main() {
    while(1) {
        pthread_mutexattr_init(&mattr);
        pthread_condattr_init(&cattr);
	pthread_condattr_destroy(&cattr);
	pthread_mutexattr_destroy(&mattr);
    }
}
