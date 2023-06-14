#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "minish.h"
#include "wrappers.h"

/*
Cambia del directorio actual al directorio asignado
Si no se le pasan inputs, cambia al $HOME. Si se le pasa un parametro, cambia a ese directorio
Si viene la bandera -, cambia al directorio anterior
Devuelve el status
*/

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
        int tmp_length = strlen(tmp_path);
        int dir_length = strlen(argv[1]);
        char *new_pwd = malloc_or_exit(tmp_length + dir_length + 2); //Hay que liberarlo
        strcpy(new_pwd, tmp_path);
        strcat(new_pwd, "/");
        strcat(new_pwd, argv[1]);
        setenv("PWD", new_pwd ,1);
        free(new_pwd);
        return 0;
    }
    printf("La carpeta ingresada no existe\n");
    return 1;
}