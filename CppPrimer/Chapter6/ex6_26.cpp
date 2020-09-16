#include <iostream>
#include <string>
int main(int argc, char **argv)
{
  for (auto p = argv + 1; p < argv + argc; p++)
    std::cout << (std::string)*p + " ";

  // std::string s;
  // for (int i = 1; i < argc; i++)
  //   s += static_cast<std::string>(argv[i]) + " ";
  // std::cout << s << std::endl;

  return 0;
}