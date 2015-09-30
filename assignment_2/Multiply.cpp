/*
 * Java returns an ArrayOutofBoundsException while the C++ program returns 0.
 * This is because Java only allows safe array traversel so accesing an index outside of 
 * of the array length - 1, Java will return an error while in C++ traversing to the length of an array
 * will return null and farther then that will return undefined behavior.
 */

#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 2, 3};
    int sum = 0;

    for(int i = 0; i <= 3; i++)
        sum *= a[i];

    cout << sum <<  " = 6" << endl;

    return 0;
}
