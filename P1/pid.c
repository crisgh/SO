/*
	gcc -o 8.pid -Wall -Wshadow pid.c && 8.pid
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char* argv[])
{
	/*pid_t p;*/

	p = getpid();
	printf("pid is %d\n", p);
	exit(0);
}
