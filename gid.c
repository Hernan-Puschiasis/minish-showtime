#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <grp.h>
#include "minish.h"
#include "wrappers.h"

int builtin_gid (int argc, char ** argv){
    if(argc>1){
        fprintf(stderr,"Comando NO admite parametros\n");
        return 1;
    }
    if(strcmp("gid",argv[0])!=0){
        fprintf(stderr,"Error a la hora de ejecutar comando\n");
        return 1;
    }
    gid_t groups_id[500];
    int groups_number = getgroups(500,groups_id);
    if(groups_number == -1){
        fprintf(stderr,"Error a la hora de ejecutar comando\n");
        return 1;
    }
    fprintf(stdout,"Real Gid: %i(%s)\n",(int) getgid(), (getgrgid(getgid()))->gr_name);
    fprintf(stdout,"Groups: ");
    for(int i = 0; i<(groups_number-1); i++){
        fprintf(stdout,"%i(%s), ",(int) groups_id[i], (getgrgid(groups_id[i]))->gr_name);
    }
    fprintf(stdout,"%i(%s)\n",(int) groups_id[groups_number-1], (getgrgid(groups_id[groups_number-1]))->gr_name);
    return 0;
}