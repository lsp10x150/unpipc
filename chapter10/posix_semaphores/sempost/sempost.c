#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    sem_t *sem;
    int value;

    if (argc != 2) {
        printf("usage: sempost <name>");
        return 1;
    }
    sem = sem_open(argv[1], 0);
    if (sem == SEM_FAILED) {
        perror("sem_open failed");
        return 2;
    }
    if ( sem_post(sem) == -1) {
        perror("sem_post failed");
        return 3;
    }
    if ( sem_getvalue(sem, &value) == -1) {
        perror("sem_getvalue failed");
        return 4;
    }
    printf("value = %d\n", value);
    if ( sem_close(sem) == -1 ) {
        perror("sem_close failed");
        return 5;
    }
    return 0;
}
