import sys
import ctypes
#from ..lib.libgame import gameGuessNumber

def main():
    Game = ctypes.cdll.LoadLibrary("../lib/libgame.so")
    while True:
        Game.gameGuessNumber()

if __name__ == '__main__':
    sys.exit(main())
