#ifndef CMDLINE_PARSER
#define CMDLINE_PARSER
#include <getopt.h>

#define ERRBUF_SIZE 256

typedef static struct cmdline_arguments {
	struct option opt;
	char* optarg;
}cmdargs;

enum retcodes {
	SUCCESS=0,
	FAILURE,
	INSUFFICIENT_ARGUMENTS
};

/* Argument list; dynamically allocated */
cmdargs *arglist;
static char errbuf[ERRBUF_SIZE];

static void
fillbuf(char* buf, size_t size, const char* content)
{
	memset(buf, '\0', size);
	assert(strlen(content)<=size);
	snprintf(buf, size, "%s\n", content);
}

/* Can be extended further to perform other sanity checks */
static int 
sanity_check(const int argc)
{
	if(argc==1) {
		fillbuf(errbuf, ERRBUF_SIZE, 
			"Insufficient command line arguments!");
		return FAILURE;
	}
}

static int
parse_longopt(const int optindex, struct option* opts)
{
	
}

static inline int
parse_cmdline(const int argc, char** argv, const char* sopt, 
		struct option *opts)
{
	int c, optindex;
	if(sanity_check(argc) == FAILURE)
		return 1+fprintf(stderr, "%s\n", errbuf);
	for(;;){
		optindex = -1;
		c = getopt_long(argc, argv, sopt, opts, &optindex);
		if(c<0)
			break;
		if(optindex>=0) {
#ifdef DEBUG
			fprintf(stderr,"Processing a longoption at index %d, %c\n" , 
				optindex, c);
#endif
			parse_longopt(optindex, opts);
		}
	}
}

#endif
