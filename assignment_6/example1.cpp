#include <cstdlib>
#include <string>
#include <vector>
//#include <boost/numeric/ublas/vector.hpp>
//#include <boost/fusion/algorithm/transformation/push_back.hpp>
//#include <boost/fusion/include/push_back.hpp>
#include <boost/interprocess/containers/vector.hpp>

using namespace std;
//namespace vboost = boost::numeric::ublas;
//namespace aboost = boost::fusion;
namespace vboost = boost::interprocess;


int main() {
  string * s1 = new string("mario");
  string * s2 = new string("luigi");
  string * s3 = new string("toad");

  vboost::vector<string *> v1;
//  aboost::push_back(v1, s1);
//  aboost::push_back(v1, s2);
//  aboost::push_back(v1, s3);

  v1.push_back(s1);
  v1.push_back(s2);
  v1.push_back(s3);

  vboost::vector<string *> v2;

//  aboost::push_back(v2, v1[rand() % v1.size()]);
  v2.push_back(v1[rand() % v1.size()]);

  return 0;
}
