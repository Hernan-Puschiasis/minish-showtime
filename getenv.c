#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"

/*
Imprime todos los valores de las variables de entorno pasadas por parametro
En caso de que no existan devuelve un mensaje por defecto.
Retorna el status de la operacion.
*/

int builtin_getenv(int argc, char ** argv){
    if(argc <= 1){
        printf("%s\n", "Falta pedir las variables de entorno");
        return 1;
    }
    for(int i = 1; i < argc; i++){
        printf("%s=%s\n", argv[i], (getenv(argv[i]) != NULL)? getenv(argv[i]) : "No existe esta variable de entorno");
    }

    return 0;
}