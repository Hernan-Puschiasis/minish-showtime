#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"

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