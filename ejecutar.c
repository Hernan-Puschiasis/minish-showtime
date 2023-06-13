#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"

/*
Toma como inputs argc y argv.
En caso de detectarse un comando interno lo ejecuta y devuelve su status
Sino ejecuta comando externo
*/

int ejecutar (int argc, char ** argv){
    struct builtin_struct *command_struct = take_command(argv[0]); //Función auxiliar
    if(command_struct == NULL){
        return externo(argc, argv);
    }
    return command_struct -> func(argc, argv);
}