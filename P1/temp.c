#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <err.h>

int
main(int argc, char *argv[])
{
	char *tmpd; /* TMPDIR es una cadena (char)*/
	char *user;/* USER es char*/
	
	pid_t p;/* es el tipo de int de pid*/
	
	/* En el terminal para exportar la variable --> TMPDIR=loquesea // export TMPDIR 
	 * luego vaciamos con unset USER */
	
	tmpd = getenv("TMPDIR"); /* nos devuelve el valor*/
	if (tmpd == NULL)
		tmpd = "/tmp";
	user = getenv("USER");
	if (user == NULL)
		errx(1," NO USER");
	p = getpid();
	if (tmpd == NULL){
		printf("%s/%s/%d\n", tmpd , user , p );
	}else{
		printf("%s/%s/%d\n" , tmpd ,user , p );
	}
	exit(EXIT_SUCCESS);
}
