#include <sys/file.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define SEQFILE "seqno"

void my_lock(int fd) {
	return;
}

void my_unlock(int fd) {
	return;
}

void my_error(const char* msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char** argv) {
	int 		fd;
	long 		i, seqno;
	pid_t 		pid;
	ssize_t 	n;
	char 		line[257];
	setvbuf(stdout, NULL, _IONBF, 0);
	pid = getpid();
	fd = open(SEQFILE, O_RDWR | O_CREAT, 0644);
	if (fd == -1) my_error("open");
	
	for (i = 0; i < 20; i++) {
		my_lock(fd);
		lseek(fd, 0L, SEEK_SET);
		n = read(fd, line, 256);
		if (n == -1) my_error("read");
		line[n] = 0;
		n = sscanf(line, "%ld\n", &seqno);
		write(STDOUT_FILENO, argv[0], strlen(argv[0]));
		write(STDOUT_FILENO, ": pid = ", 8);
		n = snprintf(line, 256, "%ld", (long)pid);
		write(STDOUT_FILENO, line, n);
		write(STDOUT_FILENO, ", seqno#: ", 10);
		n = snprintf(line, 256, "%ld", seqno);
	        write(STDOUT_FILENO, line, n);
		write(STDOUT_FILENO, "\n", 1);
		seqno++;
		snprintf(line, sizeof(line), "%ld\n", seqno);
		lseek(fd, 0L, SEEK_SET);
		write(fd, line, strlen(line));
		my_unlock(fd);
	}
	exit(0);
}
