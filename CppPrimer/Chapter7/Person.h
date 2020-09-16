#ifndef PERSON_H
#define PERSON_H
#include<string>
#include "Code\CppPrimer\using.h"

/* 7.9 */
std::istream &read(std::istream &in, Person &p);
std::ostream &print(std::ostream &out, const Person &p);

/* 7.4 - 7.5 */
class Person
{
  public:
    Person() = default;
    Person(const std::string &n, const std::string &a):name(n), address(a) {}
    Person(std::istream &in);
    std::string getname() const{ return name;} /* 可以是const的，因为无需改变对象成员，而且const函数兼容性更高 */
    std::string getaddress() const { return address;}
  private:
    std::string name;
    std::string address;
};

Person::Person(std::istream &in)
{
  read(in, *this);
}

istream &read(istream &is, Person &p)
{
  is >> p.name >> p. address;
  return is;
}

ostream &print(ostream &os, const Person &p)
{
  os << p.name << p.address;
  return os;
}

#endif