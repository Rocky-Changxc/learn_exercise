#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;
typedef string::size_type sz;
// string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');

sz wd = 80;
char def = ' ';
sz ht();
string screen(sz = ht(), sz = wd, char = def);

int main(void)
{
  vector<int> vec(10);
  cout << vec.size() << endl;
  return 0;
}

sz ht()
{
  return 10;
}

string screen(sz ht, sz wid, char backgrnd)
{
  ostringstream oss;
  oss << "ht = " << ht << " wid =" << wid << " : " << backgrnd;
  return oss.str();
}

