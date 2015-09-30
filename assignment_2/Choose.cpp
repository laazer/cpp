/*
 * Java program does not compile unless the program returns in all instancess
 * C++ program returns but in an insternce of and undefined case the the behavior is also undefined
 */

#include <string>
#include <iostream>
using namespace std;


static string choose(int n)
{
	switch(n) {
        case 0: return "zero";
        case 1: return "one";
        case 2: return "two";
	}
}
    

int main()
{
    cout << choose(0) << endl;
    cout << choose(2) << endl;
    cout << choose(4) << endl;

    return 0;
}
