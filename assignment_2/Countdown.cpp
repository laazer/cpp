/*
 * Java program does not compile unless all variables that are used are initialized.
 * C++ program has a default initialization for variables of type int.
 */

#include <iostream>
using namespace std;

static void countdown()
{
    int downto;
    for(int i = 10; i >= downto; i--) {
        cout << i << endl;
    }
    cout << "Blastoff!" << endl;
}

int main()
{
    countdown();
    return 0;
}
