#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
/* TODO : 
 *-1. initialize logging.
 * 0. Put checks on argc.
 * 1. check if optarg mexid is a valid int.
 * 2. If a mexid is not provided explicitly, then it
 * 	should have some default value, which I suppose 
 * 	should be hash of the file name. 
 * 3. Make sure the program is run as a previliged user.
 * */ 


const char* file;
int mexid;
int debug;

static int parse_cmdline(int argc, char** argv, 
		const struct option* lopt, 
		const char* sopt, char* errbuf)
{
	int c;
	int loptindex; /* long option index */
	if(!lopt || !sopt) 
		return 1 + sprintf(errbuf, 
			"Null command line options\n");
	for(;;) {
		loptindex = -1;
		c = getopt_long(argc, argv, sopt, lopt, &loptindex);
		if(c<0)
			break;
		switch(c) {
			case 0:
				break;
			case 'm': 
				mexid = atoi(optarg);
				break;
			case 'f':
				file = strdup(optarg);
				break;
			case 'd':
				debug = atoi(optarg);
				break;
			default:
				return 1+sprintf(errbuf, 
				"Option '%c' is not supported\n", c);
		}
	}
	return 0;
}

static void mexecho(void)
{
		
}

int main(int argc, char* argv[])
{
	const struct option longopts[]={
		{"file", required_argument, 0, 'f'},
		{"mexid", required_argument, 0, 'm'},
		{"debug", required_argument, 0, 'd'},
		{0, 0, 0, 0}
	};
	const char* shortopt = "f:m:d:";
	char errbuf[1024];

	if(parse_cmdline(argc, argv, longopts, shortopt, errbuf)) {
		fprintf(stderr, "%s\n", errbuf);
		exit(EXIT_FAILURE);
	}
	if(debug)
		fprintf(stderr,"file = %s, mexid = %d\n", file, mexid);
	mexecho(file, mexid);
	return 0;
}
