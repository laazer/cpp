/*
 * Java program returns a StringIndexOutofBoundsError.
 * C++ program will return but has undefined behavior when the string index is out of bounds.
 */

#include <string>
#include <iostream>
using namespace std;

int main()
{
    string in = "Hello, world!";
    int length = 16;
    string out = "";

    for (int i = length / 2; i < length; i ++) {
        out += in[i]; // NOTE: use [] operator in C++
    }

    cout << out <<  " " << out.length() << endl;

    return 0;
}
