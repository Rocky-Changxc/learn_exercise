#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

bool valid(const std::string &s)
{
  return std::isdigit(s[0]);
}

const std::string format(const std::string &s)
{
  return s.substr(0, 3) + "-" + s.substr(3, 4) + "-" + s.substr(7);
}

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
    std::ostringstream badNums, formatted;
    for (const auto &j : p.phones)
      {
        if (valid(j))
          formatted << format(j) << " ";
        else
          badNums << j << " ";
      }
    if (badNums.str().empty())
      std::cout << p.name << " " << formatted.str() << std::endl;
    else
      std::cerr << p.name << " err num(s):" << badNums.str() << std::endl; 
  }
}