#ifndef _SCREEN_H
#define _SCREEN_H
#include <string>
#include <iostream>
class Screen
{
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wh) : height(ht), width(wh), contents(ht * wh, ' '){}
  Screen(pos ht, pos wh, char c) : height(ht), width(wh), contents(ht * wh, c){}
  char get() const{
    return contents[cursor];
  }
  char get(pos ht, pos wh) const;
  Screen &move(pos r, pos c);
  Screen &set(char ch);
  Screen &set(pos r, pos c, char ch);
  Screen &display(std::ostream &os){os << contents; return *this;}
private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents; 
};

inline char Screen::get(pos ht, pos wh) const{
  return contents[ht * width + wh];
}

inline Screen &Screen::move(pos r, pos c)
{
  cursor = r * width + c;
  return *this;
}

inline Screen &Screen::set(char ch)
{
  contents[cursor] = ch;
  return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
  contents[r * width + c] = ch;
  return *this;
}
#endif