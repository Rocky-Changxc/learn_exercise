#include <iostream>
#include <vector>
int main()
{
  std::vector<int> vint;
  for (int i = 0; i < 10; ++i)
    vint.push_back(i);
  for (auto iter = vint.begin(); iter != vint.end(); iter++)
    {
      std::cout << *iter << " ";
      *iter *= 2;
    }
  std::cout << std::endl;
  for (auto iter = vint.begin(); iter != vint.end(); iter++)
    {
      std::cout << *iter << " ";
    }
  auto iter = vint.begin();
  iter += 12;
  if (iter == vint.end())
    std::cout << "true" << std::endl;
  if (iter > vint.end())
    std::cout << ">" << std::endl;
  return 0;
}