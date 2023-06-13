# La variable CC indica el ejecutable para el compilador C (usualmente son gcc o clang)
CC=gcc
# La variable CFLAGS indica las banderas para el compilador C
CFLAGS=-Wall -Wextra -std=gnu99 -ggdb
# La variable LDLIBS indica las banderas para la parte del "loader", usualmente librerías "-lxxxx"
LDLIBS=-lubsan


minish: minish.o lista.o wrappers.o linea2argv.o exit.o getenv.o setenv.o help.o pid.o uid.o status.o unsetenv.o ejecutar.o externo.o cd.o auxiliar_functions.o gid.o history.o dir.o
minish.o: wrappers.h minish.h lista.h
linea2argv.o: wrappers.h minish.h
exit.o: wrappers.h minish.h
getenv.o: wrappers.h minish.h
setenv.o: wrappers.h minish.h
help.o: wrappers.h minish.h
pid.o: wrappers.h minish.h
uid.o: wrappers.h minish.h
status.o: wrappers.h minish.h
ejecutar.o: wrappers.h minish.h
externo.o: wrappers.h minish.h
auxiliar_functions.o: wrappers.h minish.h lista.h
unsetenv.o: wrappers.h minish.h
gid.o: wrappers.h minish.h
cd.o: wrappers.h minish.h
lista.o: wrappers.h lista.h
history.o: wrappers.h minish.h lista.h
dir.o: wrappers.h minish.h lista.h
