
__start__: test_arytmetyki
	rm -f core*; ./test_arytmetyki

test_arytmetyki: obj/glowny.o obj/lzespolona.o
	g++ -o test_arytmetyki obj/glowny.o obj/lzespolona.o

obj/glowny.o: src/glowny.cpp inc/lzespolona.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/glowny.o src/glowny.cpp

obj/lzespolona.o: src/lzespolona.cpp inc/lzespolona.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/lzespolona.o src/lzespolona.cpp

clean:
	rm obj/*.o test_arytmetyki
