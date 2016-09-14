#ifndef CMDLINE_PARSER
#define CMDLINE_PARSER

#include <getopt.h>

enum RETCODES {
	FAILURE = -1,
	SUCCESS
};

struct arg {
	const struct option *opt;
	char *value;
};

/* A list of all the arguments supplied on the command line */
extern struct arg *arglist;
#endif
