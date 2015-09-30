/*
 * Java program returns each element in the array created by the functions oddNumbers and evenNumbers.
 * C++ program does not return the elements from the array created in oddNumbers or evenNumbers because
 * when the function ends, the array defined in oddNumbers and evenNumbers is removed from the stack and no 
 * longer exists. This is still true even when doReturn attempts to create a pointer for these arrays.
 */

#include <iostream>
using namespace std;

static int * doReturn(int * ret)
{
    return ret;
}

static int * oddNumbers()
{
    int numbers [] = {1, 3, 5, 7};
    return doReturn(numbers);
}

static int * evenNumbers()
{
    int numbers [] = {2, 4, 6, 8};
    return doReturn(numbers);
}

int main()
{
  	int * odd = oddNumbers();
	int * even = evenNumbers();
	
	for (int i = 0; i < 4; i ++) {
	    cout << odd[i] << " " << even[i] << endl;
	}

  return 0;
}
