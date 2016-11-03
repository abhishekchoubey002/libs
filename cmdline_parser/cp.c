#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cp.h"

int main(int argc, char* argv[])
{
	struct option opt[]={
		{"one", required_argument, 0, '1'},
		{"two", required_argument, 0, '2'},
		{"three", required_argument, 0, '3'},
		{"four", required_argument, 0, '4'},
		{0,0,0,0}
	};
	const char* shortopt = "1:2:3:4:";
	parse_cmdline(argc, argv, shortopt, opt);
}
