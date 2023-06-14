#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"

//Retorna el status de la ultima operacion. No tiene parametros
int builtin_status(int argc, char ** argv){
    if(argv[0]){}
    
    if(argc != 1){
        printf("%s\n", "La funcion status no requiere parametros");
        return 1;
    }
    printf("%s%d\n", "Status: ", globalstatret);
    return 0;
}
