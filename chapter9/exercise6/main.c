#include <sys/file.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define SEQFILE "seqno"
#define MAXLINE 256

void my_error(const char* msg) {
    perror(msg);
    exit(1);
}

void my_lock(int fd) {
    return;
}

void my_unlock(int fd) {
    return;
}

int
main(int argc, char **argv)
{
    int		fd;
    long	i, nloop, seqno;
    ssize_t	n;
    char	line[MAXLINE + 1];

    if (argc != 2)
        my_error("usage: loopmain <loopcount>");
    nloop = atol(argv[1]);

    fd = open(SEQFILE, O_RDWR | O_NONBLOCK, 0644);

    for (i = 0; i < nloop; i++) {
        my_lock(fd);				/* lock the file */

        lseek(fd, 0L, SEEK_SET);	/* rewind before read */
        n = read(fd, line, MAXLINE);
        line[n] = '\0';				/* null terminate for sscanf */

        n = sscanf(line, "%ld\n", &seqno);
        seqno++;					/* increment sequence number */

        snprintf(line, sizeof(line), "%ld\n", seqno);
        lseek(fd, 0L, SEEK_SET);	/* rewind before write */
        write(fd, line, strlen(line));

        my_unlock(fd);				/* unlock the file */
    }
    exit(0);
}

