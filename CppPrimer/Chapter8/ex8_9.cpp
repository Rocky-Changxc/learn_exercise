#include <iostream>
#include <sstream>

std::istream& getdata(std::istream &is)
{
  std::string a; /* 初次使用的char，效果应该是一致的 */
  while(is >> a)
    {
      std::cout << a << " ";
    }
  is.clear();
  return is;
}

int main()
{
  std::string str = "hello world! hhh";
  std::istringstream istrm(str);
  getdata(istrm);
  return 0;
}

