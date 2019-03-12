#ifndef GUESS_NUMBER_H
#define GUESS_NUMBER_H
#ifdef _WIN32
    #define DLLEXPORT extern "C" __declspec(dllexport)
#elif _WIN64
    #define DLLEXPORT extern "C" __declspec(dllexport)
#elif __linux__
    #define DLLEXPORT extern "C"
#elif __unix
    #define DLLEXPORT extern "C"
#endif

#include<iostream>
#include<ctime>
#include<cmath>

long numberGen(int *arr, int n);
void numberSplit(int *A, long x, int n);
int CharToInt(char c);
void getUserInput(int *A, int digit);
bool checkAnswer(int *A, int *B, int n);
DLLEXPORT void gameGuessNumber();
//extern "C" void gameGuessNumber();

#endif
