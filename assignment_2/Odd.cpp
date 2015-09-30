/*
 * Java program returns each element in the array created by the function oddNumbers.
 * C++ program does not return the elements from the array created in oddNumbers because
 * when the function ends, the array defined in oddNumbers is removed from the stack and no longer exists.
 */

#include <iostream>
using namespace std;


static int * oddNumbers()
{
    int numbers []= {1, 3, 5, 7};
    return numbers;
}

int main()
{
    int * odd = oddNumbers();
	
	for (int i = 0; i < 4; i ++) {
        cout << odd[i] << endl;
    }
    return 0;
}
