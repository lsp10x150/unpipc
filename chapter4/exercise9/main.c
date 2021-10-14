#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>

int main() {
    fd_set set;
    FD_ZERO(&set);
    int fd[2] = {0};
    int res = pipe(fd); if (res == -1) perror("pipe");
    if ( fork() == 0 ) {
        res = close(fd[0]); if (res == -1) perror("close");
        sleep(5);
        exit(0);
    }
    res = close(fd[0]); if (res == -1) perror("close");
    sleep(3);
    FD_SET(fd[1], &set);
    res = select(fd[1]+1, NULL, &set, NULL, 0); if (res == -1) perror("select");
    res = printf("select returned:[%d]\n", res); if (res == -1) perror("printf");
    if (FD_ISSET(fd[1], &set)) {
        printf("fd[1] is writable\n");
        res = write(fd[1], "hello", 5); if (res == -1) perror("last write");
    }
    return EXIT_SUCCESS;
} 
