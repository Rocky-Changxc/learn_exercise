#include <iostream>
#include <vector>
#include <windows.h>
// #include "screen.h"
#include "account.h"
using namespace std;

double Account::interestRate = initRate();
int main()
{
  Account own("cxc", 1000);
  own.set_rate(0.021);
  own.calculate();
  cout << own.get_amount() << endl;
  system("pause");
  return 0;
}
