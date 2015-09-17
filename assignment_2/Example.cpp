/*
 * Explanation goes here.
 */

// example C++ program
#include <iostream>
#include <string>

int sqr(int x) {
  return x * x;
}

int main() {
  int vals1[] = { 1, 2, 3, 4 };
  int * vals2 = vals1;

  std::string text = " squared is ";
  for(int i = 0; i < 4; i++) {
    std::cout << vals2[i] << text << sqr(vals2[i]) << std::endl;
  }

  return 0;
}
