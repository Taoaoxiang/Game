#ifndef GAME_GUESS_NUMBER_H
#define GAME_GUESS_NUMBER_H

#include<iostream>
#include<ctime>
#include<cmath>

long numberGen(int *arr, int n);
void numberSplit(int *A, long x, int n);
int CharToInt(char c);
void getUserInput(int *A, int digit);
bool checkAnswer(int *A, int *B, int n);
void gameGuessNumber();


#endif
