#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*para el read*/
#include <err.h>
char
main(char argc, char* argv[]){
  char *Cadena;
 
    printf("Pedir Cadena");
    scanf("%s",&Cadena);
 
    int len =  strlen(Cadena)-1;
 
    for(int i = 0 ; i < len; i++)
    {
      printf("\n\n%s",Cadena[i]);
    }
	exit(0);
}
