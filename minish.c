#include <stdio.h>
#include "wrappers.h"
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include "minish.h"

char line[MAXLINE];

int globalstatret = 0;
struct builtin_struct builtin_arr[] = {
        { "cd", builtin_help, HELP_CD },
        { "dir", builtin_help, HELP_DIR },
        { "exit", builtin_exit, HELP_EXIT },
        { "help", builtin_help, HELP_HELP },
        { "history", builtin_help, HELP_HISTORY },
        { "getenv", builtin_getenv, HELP_GETENV },
        { "pid", builtin_pid, HELP_PID },
        { "setenv", builtin_setenv, HELP_SETENV },
        { "status", builtin_status, HELP_STATUS },
        { "uid", builtin_uid, HELP_UID },
        { NULL, NULL, NULL }
    }; ;

int main(){
    char **argv = calloc_or_exit(MAXWORDS, MAXLINE);
    int argc;
    uid_t uid = getuid();
    struct passwd *p = getpwuid(uid);

    fprintf(stderr,  "(minish) " RED"%s" RESET ":" CYAN "%s$ " RESET, p -> pw_name, getenv("PWD"));
    while(fgets(line, MAXLINE, stdin) != NULL){ 
        argc = linea2argv(line, MAXWORDS, argv);
        
        if(argc > 0){
            globalstatret = ejecutar(argc,argv);
        }
        
        
        //Se libera el contenido de argv
        for(int i = 0; i < argc; i++){
            free(argv[i]);
        }
        fprintf(stderr,  "(minish) " RED"%s" RESET ":" CYAN "%s$ " RESET, p -> pw_name, getenv("PWD"));
    }
}