#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <err.h>
#include <fcntl.h>


int 
main(int argc, char* argv[])
{
//	pid_t p;
	int i;
	if(argc == 1){
		err(1,"faltan argumentos en la entrada");
	}else if (argc > 1 ){
		for (i=0; i< argc;i++){
			printf("%s\n",argv[i]);
			switch(fork()){
				case -1:
					err(1, "no fork");
					break;
				case 0:
					printf("encuentra el hijo, es el argumento argv[1..n]");
					break;
				default:
					printf("foork hecho %d\n", getpid());
			}
				
		}			
			
	}
	
		
exit(0);
}

// tengo que recorrerme todos los directorios y borrar 
//(hasta que no sepa que funciona bien poner un print antes que el ulick..este tendria que borrarlo.)
// dentro de un directorio si no hay nada que borrar se "suicida " el proceso
// abro y leo todos los archivos que eswten en argv[i]
// con fork creo al hijo y con execl saco el sha512sum .. execl("/usr/bin/sha512sum","nombre del fichero",NULL)
// man 2 fork
