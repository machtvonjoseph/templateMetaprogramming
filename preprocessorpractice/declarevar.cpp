#include <boost/preprocessor/repetition/repeat.hpp>
#include <iostream>
#define DECL(z, n, text) text ## n = n;


class MyClass{
    public:
    BOOST_PP_REPEAT(5, DECL, int a_) // expands to int a_0 = 0; int a_1 = 1; ...
};

using namespace std;
int main()
{
  MyClass m;
  m.a_0 = 43;
  cout<< m.a_0 <<endl;
  return 0;
}