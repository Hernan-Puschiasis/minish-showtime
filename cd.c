#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "minish.h"
#include "wrappers.h"

int builtin_cd (int argc, char ** argv){
    
    if(argc > 2){
        fprintf(stderr, "Cantidad incorrecta de argumentos");
        return 1;
    }

    int is_correct = 1;
    
    if(argc == 1){
        is_correct = !chdir(getenv("HOME"));
        char *tmp_path = getenv("PWD");

        if(is_correct){
            last_path = tmp_path;
            setenv("PWD", getenv("HOME") ,1);
            return 0;
        }
        return 1;
        
    }

    if(strcmp(argv[1],"-") == 0){
        char *tmp_path = getenv("PWD");
        is_correct = !chdir(last_path);

        if(is_correct){
            setenv("PWD", last_path ,1);
            last_path = strdup_or_exit(tmp_path);
            return 0;
        }
        return 1;
    }

    is_correct = !chdir(argv[1]);
    char *tmp_path = getenv("PWD");
    if(is_correct){
        last_path = strdup_or_exit(tmp_path);
        strcat(tmp_path, "/");
        strcat(tmp_path, argv[1]);
        setenv("PWD", tmp_path ,1);
        return 0;
    }
    printf("La carpeta ingresada no existe\n");
    return 1;

    
    

    return 0;
}