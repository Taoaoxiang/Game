SOURCE_FILES='src/GuessNumber.cpp'
OUTBIN='lib/libgame.so'

ALL:
	[ ! -d "./lib" ] && mkdir lib || echo
	g++ -std=c++11 -Wall -fPIC -o3 -shared $(SOURCE_FILES) -o $(OUTBIN)
