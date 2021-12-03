#include <sys/file.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define SEQFILE "seqno"

void my_error(const char* msg) {
    perror(msg);
    exit(1);
}

void my_lock(int fd) {
	struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    int n = fcntl(fd, F_SETLKW, &lock);
    if (n == -1) my_error("fcntl lock");
}

void my_unlock(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    int n = fcntl(fd, F_SETLKW, &lock);
    if (n == -1) my_error("fcntl unlock");
}


int main(int argc, char** argv) {
    int 		fd;
    long 		i, seqno;
    pid_t 		pid;
    ssize_t 	n;
    char 		line[257];

    pid = getpid();
    fd = open(SEQFILE, O_RDWR, 0644);
    if (fd == -1) my_error("open");

    for (i = 0; i < 20; i++) {
        my_lock(fd);
        lseek(fd, 0L, SEEK_SET);
        n = read(fd, line, 256);
        if (n == -1) my_error("read");
        line[n] = 0;
        n = sscanf(line, "%ld\n", &seqno);
        printf("%s: pid = %ld, seq# = %ld\n", argv[0], (long)pid, seqno);
        seqno++;
        snprintf(line, sizeof(line), "%ld\n", seqno);
        lseek(fd, 0L, SEEK_SET);
        write(fd, line, strlen(line));
        my_unlock(fd);
    }
    exit(0);
}
