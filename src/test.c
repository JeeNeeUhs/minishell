#include <stdio.h>
#include "inbuild.h"


int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	echo(NULL, argv);
	return (0);
}