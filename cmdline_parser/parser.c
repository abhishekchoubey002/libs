/*
 * parser.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int flag;
#define THREE 3

/* TODO: Some initializations... logging */

static int parse(const unsigned char c, const struct option *lopt, 
		const char *sopt, const int optindex)
{
	if()	
}

int parse_cmdline(const int argc, char** const argv, 
		const struct option *lopt, const char *sopt)
{
	int c;
	int optindex;

	if(!lopt || !sopt)
		return FAILURE;
	for(;;) {
		optindex = -1; /* used only when a longopt is specified */
		c = getopt_long(argc, argv, sopt, lopt, &optindex);
		if(c < 0)
			break;
		switch(c) {
			case '?':
				fprintf(stderr, "'%c' is an invalid shortopt.\n");
				help();
			case 0:
				break;
			default:
				/* this is where we address all the options.
				 * If optindex > -1, then we process a longopt
				 * else we process a shortopt */
				parse(c, lopt, sopt, optindex);
		}
	}
}


int main(int argc, char* argv[])
{
	const struct option longotps[]={
		{"one", required_argument, 0, '1'},
		{"two", required_argument, 0, '2'},
		{"three", no_argument, &flag, THREE},
		{0, 0, 0, 0}
	};
	const char* shortopt="1:2:";

	parse_cmdline(argc, argv, longopts, shortopt);
	return 0;
}
