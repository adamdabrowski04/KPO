CPPFLAGS=-pedantic -Wall -Iinc


__start__: obj figury
	rm -f core*; ./figury

obj:
	mkdir obj

figury: obj/kolo.o obj/kwadrat.o obj/glowny.o\
        obj/listafigurgeometrycznych.o
	g++ -o figury obj/kolo.o obj/kwadrat.o obj/glowny.o\
                      obj/listafigurgeometrycznych.o

obj/kolo.o: inc/kolo.hh src/kolo.cpp inc/figurageometryczna.hh\
            inc/kolo.hh
	g++ -c ${CPPFLAGS} -o obj/kolo.o src/kolo.cpp

obj/kwadrat.o: inc/kwadrat.hh inc/figurageometryczna.hh\
               src/kwadrat.cpp inc/kwadrat.hh
	g++ -c ${CPPFLAGS} -o obj/kwadrat.o src/kwadrat.cpp

obj/listafigurgeometrycznych.o: inc/listafigurgeometrycznych.hh\
          inc/kolo.hh inc/kwadrat.hh  inc/figurageometryczna.hh\
          src/listafigurgeometrycznych.cpp
	g++ -c ${CPPFLAGS} -o obj/listafigurgeometrycznych.o\
                              src/listafigurgeometrycznych.cpp


obj/glowny.o: inc/listafigurgeometrycznych.hh\
          inc/kolo.hh inc/kwadrat.hh  inc/figurageometryczna.hh\
          src/glowny.cpp
	g++ -c ${CPPFLAGS} -o obj/glowny.o src/glowny.cpp


doc:
	cd ../dox;  make

clean:
	rm -f core* figury obj/*


help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean - usuwa produkty kompilacji oraz program"
	@echo "  doc   - powoduje generowanie dokumentacji"
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo "  make doc       # generuje dokumentacje w doc/html"
	@echo
 