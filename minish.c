#include <stdio.h>
#include "wrappers.h"
#include "minish.h"

char line[MAXLINE];

int globalstatret = 0;
struct builtin_struct builtin_arr[] = {
        { "cd", builtin_help, HELP_CD },
        { "dir", builtin_help, HELP_DIR },
        { "exit", builtin_help, HELP_EXIT },
        { "help", builtin_help, HELP_HELP },
        { "history", builtin_help, HELP_HISTORY },
        { "getenv", builtin_help, HELP_GETENV },
        { "pid", builtin_pid, HELP_PID },
        { "setenv", builtin_help, HELP_SETENV },
        { "status", builtin_help, HELP_STATUS },
        { "uid", builtin_uid, HELP_UID },
        { NULL, NULL, NULL }
    }; ;

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