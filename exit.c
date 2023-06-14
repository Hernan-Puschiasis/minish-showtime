#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"

void update_history(void);

/*
Termina el shell, puede no tomar parametros y termina el programa con el ultimo
status de retorno almacenado en globalstatret o se le pasa por parametro
el valor en el que se quiere exitear
Retorna 1 en caso de ejecutarse con algun error.
*/

int builtin_exit(int argc, char **argv){
    
    if(argc > 2){
        fprintf(stderr, "El comando requiere como maximo dos parametros\n");
        return 1;
    }
    if(argc == 1){
        update_history();
        exit(globalstatret); 
    }
    
    char *error;
    int status = (int) strtol(argv[1], &error, 10);
    if(*error != '\0'){
        fprintf(stderr, "El parametro ingresado no es un entero\n");
        return 1;
    }

    update_history();
    exit(status);

}