CC=g++
CXXFLAGS=-g -std=c++0x -Wall `pkg-config opencv --cflags` 
# -gdwarf-3 for different format of debugging info
# -Wall to enable all compiler's warning messages
# c++0x partially support c++11 features

LDFLAGS=`pkg-config opencv --libs`  # -g for debugging symbols

all: clean trainSVM

trainSVM: imgSVM.o
	${CC} -o trainSVM *.o trainSVM.cpp ${CXXFLAGS} ${LDFLAGS}
#  use *.o to link with all .o files, otherwise will ignore all .o files

global.o: global.hpp

imgSVM.o: imgSVM.hpp global.o

clean: 
	rm -f trainSVM *.o
