#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main() {
  string * s1 = new string("mario");
  string * s2 = new string("luigi");
  string * s3 = new string("toad");

  vector<string *> v1;
  v1.push_back(s1);
  v1.push_back(s2);
  v1.push_back(s3);

  vector<string *> v2;
  v2.push_back(v1[rand() % v1.size()]);

  return 0;
}
