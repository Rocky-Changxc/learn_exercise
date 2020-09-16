#include <iostream>
#include <string>

class Ex13Test
{
private:
  std::string s;
public:
  Ex13Test(){std::cout << "default constructor" << std::endl;}
  Ex13Test(std::string s) : s(s){std::cout << "constructor:" << s << std::endl;}
  Ex13Test(const Ex13Test &){std::cout << "Ex13Test(const Ex13Test &)" << std::endl;}
  Ex13Test & operator=(Ex13Test &a){std::cout << "=" << std::endl;
    return a;}
  ~Ex13Test(){std::cout << "default destructor" << s << std::endl;}
};
