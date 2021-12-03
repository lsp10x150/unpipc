#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdlib.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char** argv) {
    sem_t *sem;
    int value;

    if (argc != 2) {
        printf("usage: semgetval <name>");
        return 1;
    }

    sem = sem_open(argv[1], 0);
    if (sem == SEM_FAILED) {
        perror("sem_open failed");
        return 2;
    }
    if ( sem_getvalue(sem, &value) == -1 ) {
        perror("sem_getval failed");
        return 3;
    }
    printf("value = %d\n", value);
    return 0;
}
