#include "gameGuessNumber.h"

using namespace std;

// Generate random number between 0 - 10^n
long numberGen(int *arr, int n)
{
    long maxIndex = pow(10, n);
    srand((unsigned)time(NULL));
    long x = (int)rand() % maxIndex;
    numberSplit(arr, x, n);
    return x;
}

// Split the number x to int array A with n digits
void numberSplit(int *A, long x, int n) 
{
    for (int i = 0; i < n; ++i){
        long m = pow(10, n-(i+1));
        A[i] = x / m;
        x = x % m;
    }
}

// Convert char to int
int CharToInt(char c)
{
    return c - 48;
}

// Check user's answer
bool checkAnswer(int *A, int *B, int n)
{
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (*(A + i) == *(B + i)) 
            ++a;
        else {
            for (int j = 0; j < n; ++j) {
                if (*(A + i) == *(B + j))
                    ++b;
            }
        }
    }
    cout << a << "A" << b << "B" << endl;
    if (a == n)
        return true;
    else
        return false;
}

void getUserInput(int *A, int digit)
{
    char c;
    for (int j=0; j<digit; ++j){
        cin >> c;
        *(A+j) = CharToInt(c);
    }   
}

void gameGuessNumber()
{
    int digit = 4;
    int chance = 2; 
    int answerArr[digit], userIn[digit];
    
    long answer = numberGen(answerArr, digit);
    cout << answer << endl;
    cout << "\n" << "==Start==" << endl;
    for (int i = 0; i <= chance; ++i){
        if (i < chance) 
            cout << "Try " << i+1 << "/" << chance << ":"<< endl;
        else if (i == chance) {
            cout << "You lost!!!\n"
                 << "The answer is: " << answer << "." << endl;
            break;
        }
        
        getUserInput(userIn, digit);

        if (checkAnswer(answerArr, userIn, digit)) {
            cout << "------\n" << "Bingo!" << endl;
            break;
        } else {
            cout << "------" << endl;
        }

    }
    cout << "==End==" << endl;
}
