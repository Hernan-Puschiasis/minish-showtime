#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"

/*
Elimina variables de ambiente. Recibe como parametros una lista de nombres de variables de ambiente.
Retorna el status.
*/
int builtin_unsetenv (int argc, char ** argv){
    if(argc < 2){
        fprintf(stderr, "La cantidad de argumentos es incorrecta");
        return 1;
    }

    int status;
    for(int i = 1; i < argc; i++){
        status = unsetenv(argv[i]);
        if(status != 0){
            fprintf(stderr, "Error al borrar la variable %s", argv[i]);
        }
    }

    return 0;
}