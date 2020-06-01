CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc
OBJ=./obj

__start__: ${OBJ} ${OBJ}/example.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/CWektor.o ${OBJ}/CMacierzKw.o ${OBJ}/MacierzOb.o ${OBJ}/Prostopadloscian.o ${OBJ}/Dron.o ${OBJ}/GraniastoslupHex.o ${OBJ}/Sruba.o ${OBJ}/Powierzchnia.o ${OBJ}/Dno.o ${OBJ}/Tafla.o ${OBJ}/PrzeszkodaPros.o
	g++ -o example.out ${OBJ}/example.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/CWektor.o ${OBJ}/CMacierzKw.o ${OBJ}/MacierzOb.o ${OBJ}/Prostopadloscian.o ${OBJ}/Dron.o ${OBJ}/GraniastoslupHex.o ${OBJ}/Sruba.o ${OBJ}/Powierzchnia.o ${OBJ}/Dno.o ${OBJ}/Tafla.o ${OBJ}/PrzeszkodaPros.o -lpthread

${OBJ}:	
	mkdir ${OBJ}

${OBJ}/example.o: src/example.cpp inc/Dr3D_gnuplot_api.hh inc/SWektor.hh inc/SMacierzKw.hh inc/MacierzOb.hh inc/Prostopadloscian.hh inc/Dron.hh inc/GraniastoslupHex.hh inc/Sruba.hh inc/Powierzchnia.hh inc/Dno.hh inc/Tafla.hh inc/PrzeszkodaPros.hh
	g++ ${CPPFLAGS} -o ${OBJ}/example.o src/example.cpp

${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

${OBJ}/CWektor.o: inc/SWektor.hh src/SWektor.cpp src/CWektor.cpp
	g++ ${CPPFLAGS} -o ${OBJ}/CWektor.o src/CWektor.cpp

${OBJ}/CMacierzKw.o: inc/SWektor.hh inc/SMacierzKw.hh src/SMacierzKw.cpp src/CMacierzKw.cpp 
	g++ ${CPPFLAGS} -o ${OBJ}/CMacierzKw.o src/CMacierzKw.cpp

${OBJ}/MacierzOb.o:  inc/SMacierzKw.hh inc/MacierzOb.hh src/MacierzOb.cpp
	g++ ${CPPFLAGS} -o ${OBJ}/MacierzOb.o src/MacierzOb.cpp

${OBJ}/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Prostopadloscian.o src/Prostopadloscian.cpp

inc/Prostopadloscian.hh: inc/Obiekt3D.hh
	touch inc/Prostopadloscian.hh

${OBJ}/Dron.o: src/Dron.cpp inc/Dron.hh inc/InterfejsDrona.hh inc/Prostopadloscian.hh inc/Sruba.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dron.o src/Dron.cpp

inc/Dron.hh: inc/InterfejsDrona.hh inc/Przeszkoda.hh
	touch inc/Dron.hh

${OBJ}/GraniastoslupHex.o: src/GraniastoslupHex.cpp inc/GraniastoslupHex.hh inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o ${OBJ}/GraniastoslupHex.o src/GraniastoslupHex.cpp

inc/GraniastoslupHex.hh: inc/Obiekt3D.hh
	touch inc/GraniastoslupHex.hh

${OBJ}/Sruba.o: src/Sruba.cpp inc/Sruba.hh  inc/GraniastoslupHex.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Sruba.o src/Sruba.cpp

${OBJ}/Powierzchnia.o: src/Powierzchnia.cpp inc/Powierzchnia.hh inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Powierzchnia.o src/Powierzchnia.cpp

inc/Powierzchnia.hh: inc/Obiekt3D.hh
	touch inc/Powierzchnia.hh

${OBJ}/Dno.o: src/Dno.cpp inc/Dno.hh  inc/Powierzchnia.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dno.o src/Dno.cpp

${OBJ}/Tafla.o: src/Tafla.cpp inc/Tafla.hh  inc/Powierzchnia.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Tafla.o src/Tafla.cpp

${OBJ}/PrzeszkodaPros.o: src/PrzeszkodaPros.cpp inc/PrzeszkodaPros.hh  inc/Prostopadloscian.hh inc/Przeszkoda.hh
	g++ ${CPPFLAGS} -o ${OBJ}/PrzeszkodaPros.o src/PrzeszkodaPros.cpp


clear:
	rm example.out ${OBJ}/*.o
