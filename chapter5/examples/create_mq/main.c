#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>

struct mq_attr attr;

int main(int argc, char** argv) {
	int c, flags;
	mqd_t mqd;
	flags = O_RDWR | O_CREAT;
	while ( (c = getopt(argc, argv, "em:z:")) != -1) {
		switch (c) {
		case 'e': 
			flags |= O_EXCL;
			break;
		case 'm':
			attr.mq_maxmsg = atol(optarg);
			break;
		case 'z':
			attr.mq_msgsize = atol(optarg);
			break;
		}
	}
	if (optind != argc - 1)
		{printf("optind != argc - 1"); exit(1);}
	if ((attr.mq_maxmsg != 0 && attr.mq_msgsize == 0) || 
		(attr.mq_maxmsg == 0 && attr.mq_msgsize != 0))
		{printf("must specify both -m maxmsg and -z msgsize"); exit(1);}
	mqd = mq_open(argv[optind], flags, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), &attr);
	if (mqd == -1) {perror("mqd == -1"); exit(1);}
	mq_close(mqd); 
	return 0; 
}
