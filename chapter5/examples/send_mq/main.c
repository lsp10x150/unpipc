#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>
#include <fcntl.h>
#include <error.h>
int main(int argc, char** argv) {
	mqd_t mqd;
	void* ptr;
	size_t len;
	uint8_t prio;
	
	if (argc != 4) 
	{perror("argc!=4"); exit(1);}
	len = atoi(argv[2]);
	prio = atoi(argv[3]);
	mqd = mq_open(argv[1], O_WRONLY);
	ptr = calloc(len, sizeof(char));
	mq_send(mqd, ptr, len, prio);
	return 0;
}
