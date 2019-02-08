import os
import ctypes

def gameGuessNumber():
    this_path = os.path.dirname(os.path.realpath(__file__))
    Game = ctypes.cdll.LoadLibrary(this_path + "/" + "../lib/libgame.so")
    Game.gameGuessNumber()
