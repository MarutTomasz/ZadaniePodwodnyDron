CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc
OBJ=./obj

__start__: ${OBJ} ${OBJ}/example.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/CWektor.o ${OBJ}/CMacierzKw.o ${OBJ}/MacierzOb.o ${OBJ}/Prostopadloscian.o ${OBJ}/Dron.o ${OBJ}/GraniastoslupHex.o ${OBJ}/Sruba.o
	g++ -o example.out ${OBJ}/example.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/CWektor.o ${OBJ}/CMacierzKw.o ${OBJ}/MacierzOb.o ${OBJ}/Prostopadloscian.o ${OBJ}/Dron.o ${OBJ}/GraniastoslupHex.o ${OBJ}/Sruba.o -lpthread

${OBJ}:	
	mkdir ${OBJ}

${OBJ}/example.o: src/example.cpp inc/Dr3D_gnuplot_api.hh inc/SWektor.hh inc/SMacierzKw.hh inc/MacierzOb.hh inc/Prostopadloscian.hh inc/Dron.hh inc/GraniastoslupHex.hh inc/Sruba.hh
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

${OBJ}/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Prostopadloscian.o src/Prostopadloscian.cpp

inc/Prostopadloscian.hh: inc/Obiekt3D.hh
	touch inc/Prostopadloscian.hh

${OBJ}/Dron.o: src/Dron.cpp inc/Dron.hh inc/InterfejsDrona.hh inc/Prostopadloscian.hh inc/Sruba.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dron.o src/Dron.cpp

inc/Dron.hh: inc/InterfejsDrona.hh
	touch inc/Dron.hh

${OBJ}/GraniastoslupHex.o: src/GraniastoslupHex.cpp inc/GraniastoslupHex.hh
	g++ ${CPPFLAGS} -o ${OBJ}/GraniastoslupHex.o src/GraniastoslupHex.cpp

inc/GraniastoslupHex.hh: inc/Obiekt3D.hh
	touch inc/GraniastoslupHex.hh

${OBJ}/Sruba.o: src/Sruba.cpp inc/Sruba.hh  inc/GraniastoslupHex.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Sruba.o src/Sruba.cpp


clear:
	rm example.out ${OBJ}/*.o
