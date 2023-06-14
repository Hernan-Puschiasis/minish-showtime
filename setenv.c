#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"

/*
Define una variable nueva de ambiente o cambia el valor de una variable de ambiente existente.
Recibe como parametros el nombre de la variable y el valor a asignar. Retorna el status.
*/
int builtin_setenv (int argc, char ** argv){
    
    if(argc != 3){
        printf("%s\n", "Cantidad incorrecta de argumentos");
        return 1;
    }

    int status = setenv(argv[1], argv[2], 1);
    if(status == 0){
        printf("%s=%s\n",argv[1], argv[2]);
        return 0;
    }
    printf("%s\n", "Error al setear la variable global");
    return 1;

}