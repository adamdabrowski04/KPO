PROG=mnozenie


__start__: obj ${PROG} 
	./${PROG} < test.dane

obj:
	mkdir obj

${PROG}: obj/main.o
	g++ -Wall -o ${PROG} obj/main.o

obj/main.o: inc/typ.h inc/wektor.hh src/main.cpp
	g++ -c -Wall -pedantic -Iinc -o obj/main.o src/main.cpp



#^^^^^^^^^^                                 ^^^^^^^^^^^^^^^#
# Powyzje  jest miejsce na wlasne wpisy dla nowych modulow #
############################################################

clean:
	rm -f ${PROG} obj/*

help:
	@echo "\n\
 Ten plik pozwala wywolac polecenie make z nastepujacymi\n\
 podcelami:                                             \n\
                                                        \n\
   make            - kompilacja, konsolidacja i uruchomienie\n\
                     programu z aktualnym typem danych.\n\
   make double     - wymuszenie zmiany typu danych na double oraz\n\
                     kompilacja, konsolidacja i uruchomienie programu.\n\
   make Symbol     - wymuszenie zmiany typu danych na Symbol oraz\n\
                     kompilacja, konsolidacja i uruchomienie programu.\n\
   make LiczbaZespolona - wymuszenie zmiany typu danych na\n\
                     LiczbaZespolona oraz kompilacja, konsolidacja\n\
                     i uruchomienie programu.\n\
   make clean      - usuwa produkcji kompilacji i sam program.\n\
   make help       - wyswietla te inforacje.\n\
\n\
"

############################################################
#   Tego co jest ponizej nie nalezy modyfikowac.           #
#                                                          #

double: __utworz_typ_double__ clean __start__

Symbol: __utworz_typ_symbol__ clean __start__

LiczbaZespolona: __utworz_typ_lzespolona__ clean __start__

__utworz_typ_double__:
	@echo \
"\n\
#ifndef TYP_H\n\
#define TYP_H\n\
typedef double TYP;\n\
#define NAZWA_TYPU  \"double\"\n\
#endif\n\
" > inc/typ.h
	cp dane/test-double.dane test.dane


__utworz_typ_symbol__:
	@echo \
"\n\
#ifndef TYP_H\n\
#define TYP_H\n\
#include \"symbol.hh\"\n\
typedef Symbol TYP;\n\
#define NAZWA_TYPU  \"Symbol\"\n\
#endif\n\
" > inc/typ.h
	cp dane/test-symbol.dane test.dane


__utworz_typ_lzespolona__:
	@echo \
"\n\
#ifndef TYP_H\n\
#define TYP_H\n\
#include \"liczbazespolona.hh\"\n\
typedef LiczbaZespolona TYP;\n\
#define NAZWA_TYPU  \"LiczbaZespolona\"\n\
#endif\n\
" > inc/typ.h
	cp dane/test-liczbazespolona.dane test.dane

