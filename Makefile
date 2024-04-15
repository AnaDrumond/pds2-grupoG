CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/pagamento.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/pagamento.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/pagamento.o: ${INCLUDE}/pagamento.hpp ${SRC}/pagamento.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/pagamento.cpp -o ${BUILD}/pagamento.o

${BUILD}/main.o: ${INCLUDE}/pagamento.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o