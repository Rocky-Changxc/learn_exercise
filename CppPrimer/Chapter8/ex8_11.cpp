#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

#if 0
int main(int argc, char **argv)
{
  std::ifstream input(argv[1]);
  std::vector<PersonInfo> people;
  std::string line, word;
  while(getline(input, line))
  {
    PersonInfo p;
    std::istringstream istrm(line);
    istrm >> p.name;
    while (istrm >> word)
      p.phones.push_back(word);
    people.push_back(p);
  }

  for (auto p : people)
  {
    std::cout << p.name << ":";
    for (auto j : p.phones)
      std::cout << j << " ";
    std::cout << std::endl;
  }
}
#endif

int main(int argc, char **argv)
{
  std::ifstream input(argv[1]);
  std::vector<PersonInfo> people;
  std::string line, word;
  std::istringstream istrm;
  while(getline(input, line))
  {
    PersonInfo p;
    istrm.clear();
    istrm.str(line);
    istrm >> p.name;
    while (istrm >> word)
      p.phones.push_back(word);
    people.push_back(p);
  }

  for (const auto &p : people)
  {
    std::cout << p.name << ":";
    for (const auto &j : p.phones)
      std::cout << j << " ";
    std::cout << std::endl;
  }
}