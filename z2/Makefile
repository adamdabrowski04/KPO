PROG=symbole
KOM=g++ -Wall -pedantic

__start__: obj ${PROG}
	./${PROG}

${PROG}: obj/dzialania.o obj/main.o
	${KOM} -o ${PROG} obj/dzialania.o obj/main.o
obj/dzialania.o: include/dzialania.h src/dzialania.cpp
	${KOM} -c -o obj/dzialania.o src/dzialania.cpp
obj/main.o: include/dzialania.h main.cpp
	${KOM} -c -o obj/main.o main.cpp