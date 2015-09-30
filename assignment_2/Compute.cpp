/*
 * Both the C++ program and the java program behave similarly. The C++ returns a segmentation fault
 * while the java program returns a StackOverflowError. The java program takes noticebly 
 * longer to fail then the C++ program
 */

#include <iostream>
using namespace std;

static double compute(int x)
{
    if (x <= 0) {
        return 0.0;
    }

    double localdata1;
    double localdata2;
    double localdata3;
    double localdata4;
    double localdata5;

    localdata1 = compute(x - 1);
    localdata2 = compute(x - 2);
    localdata3 = compute(x - 3);
    localdata4 = compute(x - 4);
    localdata5 = compute(x - 5);

    return localdata1 - localdata2 + localdata3 - localdata4 + localdata5;
}

int main()
{
  cout << compute(1000000) << endl;
  return 0;
}
