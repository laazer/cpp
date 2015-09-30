/*
 * Java program does not even compile
 * C++ program allows for promotions and demotions of variables 
 */

#include <iostream>
using namespace std;

int main()
{
	int n = 40000;
	short m = n;
	int o = m;
    
	cout << n << " " << m << " " << o << endl;
    return 0;
}
