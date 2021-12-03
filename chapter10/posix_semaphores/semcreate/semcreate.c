#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdlib.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char** argv) {
    int c, flags;
    sem_t *sem;
    unsigned int value;

    flags = O_RDWR | O_CREAT;
    value = 1;
    while ( (c = getopt(argc, argv, "ei:")) != -1) {
        switch (c) {
            case 'e': flags |= O_EXCL; break;
            case 'i': value = atoi(optarg); break;
        }
    }
    if (optind != argc - 1) {
        printf("usage: semcreate [-e] [-i initvalue] <name>");
        return 1;
    }
    sem = sem_open(argv[optind], flags, FILE_MODE, value);
    if (sem == SEM_FAILED) {
        perror("sem_open failed");
        return 2;
    }
    if ( sem_close(sem) == -1 ) {
        perror("sem_close failed");
        return 3;
    }
    return 0;
}
