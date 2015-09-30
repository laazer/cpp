/*
 * Java program creates a pointer for each instance of the variable 'numbers' so the two arrays
 * named numbers are completly serperate and do not effect each other when printing to console.
 * C++ does not create a new pointer each instance of numbers so when numbers is given the arrays
 * in displayBoth, others is also set to that array because they are both pointing to the same
 * pointer.
 */

#include <iostream>
using namespace std;


static int * numbers()
{
    int numbers []= {-5, -6, -7, -8};
    int * ret = numbers;
    return ret;
}

static void displayBoth(int * others)
{
    int numbers []= {-1, -2, -3, -4};
    for (int i = 0; i < 4; i ++) {
        cout << numbers[i] << endl;
    }
    for (int i = 0; i < 4; i ++) {
        cout << others[i] << endl;
    }
}

int main()
{
    displayBoth(numbers());

    return 0;
}
