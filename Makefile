# La variable CC indica el ejecutable para el compilador C (usualmente son gcc o clang)
CC=gcc
# La variable CFLAGS indica las banderas para el compilador C
CFLAGS=-Wall -Wextra -std=gnu99 -ggdb
# La variable LDLIBS indica las banderas para la parte del "loader", usualmente librerías "-lxxxx"
LDLIBS=-lubsan

minish: minish.o wrappers.o linea2argv.o exit.o getenv.o setenv.o
minish.o: wrappers.h minish.h
linea2argv.o: wrappers.h minish.h
exit.o: wrappers.h minish.h
getenv.o: wrappers.h minish.h
setenv.o: wrappers.h minish.h
wrappers.o: wrappers.h