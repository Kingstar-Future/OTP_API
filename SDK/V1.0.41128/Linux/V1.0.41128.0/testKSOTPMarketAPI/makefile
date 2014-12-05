
CC=g++

CFLAGS= -O2 -fPIC

LIB= -L ../KSOTPMarketAPI/linux64 \
     -lksmarketdataapi \
     -lkslkc64r
TARGET=testKSOTPMarketAPI_64

ifeq ($(vtype),32r)
    CFLAGS+=-m32
    LIB:=$(subst linux64,linux32,${LIB})
    LIB:=$(subst lkslkc64r,lkslkc32r,${LIB})
    TARGET:=testKSOTPMarketAPI_32
endif

ifeq ($(vtype),64r)
endif

all: ${TARGET}
	cp -f ${TARGET} ../run/

${TARGET}: event.o testKSOTPMarketAPI.o
	${CC} ${CFLAGS} -o $@ $^  ${LIB} 

testKSOTPMarketAPI.o: testKSOTPMarketAPI.cpp
	${CC} ${CFLAGS} -o $@ -c $^ 

event.o:event.cpp
	${CC} ${CFLAGS} -o $@ -c $^  
clean:
	rm -f *.o  testKSMarketDataAPI_*
