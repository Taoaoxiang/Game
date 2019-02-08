SOURCE_FILES='Guess_Number/GuessNumber.cpp'
OUTBIN='lib/libgame.so'

ALL:
	g++ -std=c++11 -Wall -fPIC -o3 -shared $(SOURCE_FILES) -o $(OUTBIN)
