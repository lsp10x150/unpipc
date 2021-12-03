#include <stdio.h>
#include <semaphore.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: semunlink <name>");
        return 1;
    }
    if ( sem_unlink(argv[1]) == -1 ) {
        perror("sem_unlink failed");
        return 2;
    }
    return 0;
}
