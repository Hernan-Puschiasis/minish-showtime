#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include "minish.h"
#include "wrappers.h"

/*
Este comando NO lleva parámetros, muestra el userid como número y también el nombre de usuario.
Devuelve el status de la operación
*/
int builtin_uid (int argc, char ** argv){
    if(argc>1){
        fprintf(stderr,"Comando NO admite parametros\n");
        return 1;
    }
    if(argv[0]){}
    struct passwd *p;
    uid_t uid = getuid();
    p = getpwuid(uid);
    fprintf(stdout,"Uid: %i, Name: %s, Info: %s\n",p->pw_uid,p->pw_name,p->pw_gecos);
    return 0;
}