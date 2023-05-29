#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include "minish.h"
#include "wrappers.h"

int builtin_uid (int argc, char ** argv){
    if(argc>1){
        fprintf(stderr,"Comando NO admite parametros\n");
        return 1;
    }
    if(strcmp("uid",argv[0])!=0){
        fprintf(stderr,"Error a la hora de ejecutar comando\n");
        return 1;
    }
    struct passwd *p;
    uid_t uid = getuid();
    p = getpwuid(uid);
    fprintf(stdout,"Uid: %i, Name: %s, Info: %s\n",p->pw_uid,p->pw_name,p->pw_gecos);
    return 0;
}