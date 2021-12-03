#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    sem_t *sem;
    int value;

    if (argc != 2) {
        printf("usage: semwait <name>");
        return 1;
    }
    sem = sem_open(argv[optind],0);
    if (sem == SEM_FAILED) {
        perror("sem_open failed");
        return 2;
    }
    if ( sem_wait(sem) == -1 ) {
        perror("sem_wait failed");
        return 3;
    }
    if ( sem_getvalue(sem, &value) == -1) {
        perror("sem_getvalue failed");
        return 4;
    }
    printf("pid %ld has semaphore, value = %d\n", (long) getpid(), value);
    if ( sem_close(sem) == -1 ) {
        perror("sem_close failed");
        return 5;
    }
    return 0;
}
