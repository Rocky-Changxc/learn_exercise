#include "ex13_13.h"
#include <vector>
using namespace std;

int f1(Ex13Test a)
{
  cout << "f1" << endl;
  return 0;
}
int f2(Ex13Test &a)
{
  cout << "f2" << endl;
  return 0;
}
int main(void)
{
  Ex13Test a("123");
  f1(a);
  f2(a);
  vector<Ex13Test> vec(1);
}