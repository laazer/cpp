/*
 * Java program does returns an Arithmatic exception, cannot divide by 0
 * C++ program returns floating point exception 8
 */

#include <iostream>
using namespace std;

static int divide(int x, int y, int z) {
    return x / (y / z);
}

int main()
{
    int n = divide(3, 2, 1);
	int m = divide(1, 2, 3);
	int w = n * m;
    cout << w << endl;
    return 0;
}
