#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"


int ejecutar (int argc, char ** argv){
    struct builtin_struct *command_struct = take_command(argv[0]);
    if(command_struct == NULL){
        return externo(argc, argv);
    }
    return command_struct -> func(argc, argv);
}