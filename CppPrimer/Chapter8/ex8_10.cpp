#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main(int argc, char **argv)
{
  std::ifstream input(argv[1]);
  std::vector<std::string> vstr;
  std::string str;
  while(getline(input, str))
    vstr.push_back(str);
  
  // std::istringstream istrm;
  for(auto s : vstr)
    {
      std::cout<< "s:" << s << std::endl;
      std::istringstream istrm(s);
      // istrm.str(s);
      std::string word;
      while(istrm >> word)
        std::cout << word << " ";
      std::cout << std::endl;
    }
  return 0;
}