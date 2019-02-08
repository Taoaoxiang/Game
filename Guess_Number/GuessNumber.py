import ctypes

def gameGuessNumber():
    Game = ctypes.cdll.LoadLibrary("../lib/libgame.so")
    Game.gameGuessNumber()
