#include <iostream>
#include <vector>
#include "Person.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

/* 7.4 - 7.5 */
/* Person */
std::istream &read(std::istream &is, Person &p)
{
  is >> p.name >> p.address;
  return is;
}
std::ostream &print(std::ostream &os, const Person &p)
{
  os << "name:" + p.name << endl;
  os << "address:" + p.address << endl;
  return os;
}

int main()
{
  Person p(cin);
  // read(cin, p);
  print(cout, p);
  system("pause");
  return 0;
}

/* 7.2 */
/* struct Sales_data
{
  std::string isbn() const{return bookNo;}
  Sales_data &combine(const Sales_data &sdtemp);
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue;
};
Sales_data &Sales_data::combine(const Sales_data &sdtemp)
{
  units_sold += sdtemp.units_sold;
  revenue += sdtemp.revenue;
  return *this;
}
 */


/* 6.54-6.56
#include <iostream>
#include <vector>

using namespace std;
int rint(int a, int b)
{
  cout << a + b << endl;
}
int rintsub(int a, int b)
{
  cout << "a - b = " << a - b << endl;
}
int rintmul(int a, int b)
{
  cout << "a * b = " << a * b << endl;
}
int main()
{
  vector<decltype(rint) *> rintp{rint};
  rintp.push_back(rintsub);
  rintp.push_back(rintmul);
  for(auto p : rintp)
    p(2,1);
  getchar();
  return 0;
} */