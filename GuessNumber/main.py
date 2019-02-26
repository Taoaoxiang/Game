#!/usr/bin/env python3

# Only runs in linux
# If we want to get it work on windows,
# We have to generate .dll

import sys
import lib.GuessNumber as game

def main():
    while True:
        game.gameGuessNumber()

if __name__ == '__main__':
    sys.exit(main())
