
CC=g++

CFLAGS=-g -Wall -fPIC

LIB= -L ../lib/linux64 \
     -lksotptraderapi \
     -lkslkc64r
	 
ifeq ($(vtype),32r)
    CFLAGS= -O2  -m32 -fPIC
    LIB:=$(subst linux64,linux32,${LIB})
    LIB:=$(subst kslkc64r,kslkc32r,${LIB})
endif

ifeq ($(vtype),64r)
    CFLAGS= -O2 -fPIC
endif

all: testKSOTPTraderApi

testKSOTPTraderApi: testKSOTPTraderApi.o
	${CC} ${CFLAGS} -o $@ $^  ${LIB} 
testKSOTPTraderApi.o: testKSOTPTraderApi.cpp
	${CC} ${CFLAGS} -o $@ -c $^ 

event.o:event.cpp
	${CC} ${CFLAGS} -o $@ -c $^  
clean:
	rm *.o testKSOTPTraderApi 
