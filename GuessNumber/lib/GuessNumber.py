import os, sys
import ctypes

def gameGuessNumber():
    this_path = os.path.dirname(os.path.realpath(__file__))
    if sys.platform == "linux" or sys.platform == "linux2":
        Game = ctypes.cdll.LoadLibrary(this_path + "/GuessNumberLib.so")
    elif sys.platform == "win32" or sys.platform == "cygwin":
        Game = ctypes.WinDLL(this_path + "\GuessNumberLib.dll")
    Game.gameGuessNumber()
