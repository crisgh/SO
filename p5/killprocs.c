/*
*
gcc -o 8.killprocs -Wall -Wshadow killprocs.c && 8.killprocs

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*para el read*/
#include <err.h>
#include "signal.h"
#include "sys/types.h"
/*
static void handlerint(int numero){
  fprintf(stderr, "recibo el nº %d\n",numero );
}
signal(SIN__,handlerint);
*/
int
comprobamoscasos(int process){
  c = fork();
  switch (n) {
    case -1: //error
      fprintf(stderr, " fork failed " );
    case 0://hijo
      execl("/bin/kill","kill",process,NULL);
      err(1,"execl failer");
      exit(1);
  default://padre
      wait(&sts);
      if (sts<0){
        fprintf(stderr, " no se ha podido matar %d\n",getpid() );
      }
  }
  exit(0);
}
int
main(int argc,char* argv[])
{

  if (argv[1] = "-n"){
    for(i = 0 , i++ , argc)
    //comprobarproceso
    // argv[i] == strstr()
}
/* fgets para leer lineas -- pipes .. algo parecido a lo que nos da ps, el ultimo es el parecido
* strtok_r nos da los tokes(palabras separadas de espacios) solo nos interesa el ultimo toke(el nombre) y miramos si esta la cadena que pasamos strstr()
* solo se crea un hijo que es ps (-n), sin eso no es necesario tener un pipe
*
*/
