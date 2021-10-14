#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/signal.h>

void 
sigchld_handler(int sig) {
    printf("sigchld catched!\n");
    wait(NULL);
    if (unlink("my_fifo") == -1) perror("unlink fifo");
}

int main() {
    signal(SIGCHLD, sigchld_handler);
    struct stat s = {0};
    int res = 0;
    do {
        if (res == -1) {
            perror("mkfifo");
            unlink("my_fifo");
            errno = 0;
        }
        res = mkfifo("my_fifo", O_WRONLY | S_IRWXU);
    } while (res == -1);
    if (stat("my_fifo", &s) == -1) {perror("stat"); errno = 0;}
    printf("fifo is empty, isn't it? fifo size is [%ld] uid[%u] gid[%u] mode[%o]\n",
           s.st_size, s.st_uid, s.st_gid, s.st_mode);
    printf("now we open the fifo and write something to it\n");
    if (fork() == 0) {
        int fifofd = open("my_fifo", O_RDONLY, 0);
        char arr[1024];
        int r = read(fifofd, arr, 1024);
        arr[r] = 0;
        printf("child got [%s]\n", arr);
        exit(0);
    }
    int fifofd = open("my_fifo", O_WRONLY, 0);
    if (fifofd == -1) {perror("open fifo"); errno = 0;}
    char text[] = {"something to write to fifo"};
    res = write(fifofd, text, strlen(text));
    if (res == -1) {perror("write to fifo"); errno = 0;}
    if (res != strlen(text)) printf("fifo write -- strange!\n");
    memset(&s, 0, sizeof(s));
    if (fstat(fifofd, &s) == -1) perror("fstat");
    printf("fifo size [%ld] after writing to it\n", s.st_size);
    wait(NULL);
    
}
