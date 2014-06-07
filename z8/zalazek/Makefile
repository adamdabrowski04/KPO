#
#  To sa opcje dla kompilacji
#
<<<<<<< HEAD
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan<test.dat

uklad_rownan: obj/main.o obj/UkladRownanLiniowych.o obj/Macierz.o obj/Wektor.o obj/zespolone.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/Wektor.o\
                                   obj/Macierz.o obj/UkladRownanLiniowych.o obj/zespolone.o
=======
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11

__start__: uklad_rownan
	./uklad_rownan -t z -r 4 -o wynik.txt -i test-zesp.dat

uklad_rownan: obj/main.o obj/UkladRownanLiniowych.o obj/Macierz.o obj/Wektor.o obj/zespolone.o obj/RozpoznajProblem.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/Wektor.o\
                                   obj/Macierz.o obj/UkladRownanLiniowych.o obj/zespolone.o obj/RozpoznajProblem.o
>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2

obj/main.o: src/main.cpp inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/Wektor.hh\
        inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh
	g++ ${CPPFLAGS} -o obj/UkladRownanLiniowych.o src/UkladRownanLiniowych.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/zespolone.o: src/zespolone.cpp inc/zespolone.hh
	g++ ${CPPFLAGS} -o obj/zespolone.o src/zespolone.cpp

<<<<<<< HEAD
=======
obj/RozpoznajProblem.o: src/RozpoznajProblem.cpp inc/RozpoznajProblem.hh inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/RozpoznajProblem.o src/RozpoznajProblem.cpp

>>>>>>> 20f29c3d31f058ede2849f8c385bdb0d982face2
clean:
	rm -f obj/*.o uklad_rownan
