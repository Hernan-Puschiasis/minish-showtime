#include <stdio.h>
#include "wrappers.h"
#include "minish.h"

char line[MAXLINE];
int globalstatret = 0;

int main(){
    char **argv = calloc_or_exit(MAXWORDS, MAXLINE);
    int argc;

    fprintf(stderr, "$ ");
    while(fgets(line, MAXLINE, stdin) != NULL){ 
        argc = linea2argv(line, MAXWORDS, argv);
        //Se libera el contenido de argv
        for(int i = 0; i < argc; i++){
            free(argv[i]);
        }
        fprintf(stderr, "$ ");
    }
}