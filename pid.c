#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"
#include "wrappers.h"

/*
Este comando NO lleva parámetros, muestra el process id del shell
Devuelve el status de la operación
*/
int builtin_pid (int argc, char ** argv){
    if(argc>1){
        fprintf(stderr,"Comando NO admite parametros\n");
        return 1;
    }
    if(argv[0]){}
    fprintf(stdout,"pid: %i, ppid: %i\n",getpid(),getppid());
    return 0;
}