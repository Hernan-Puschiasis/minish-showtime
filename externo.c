#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"

int externo (int argc, char ** argv){
    return argc && argv;
}