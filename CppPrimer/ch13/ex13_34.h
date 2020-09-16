#ifndef __EX13_34
#define __EX13_34

#include <set>
#include <string>
class Folder;
class Message
{
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);

public:
  explicit Message(const std::string &s) : contents(s) {}
  Message(const Message &m) : contents(m.contents), folders(m.folders) {addToFolders(m);}
  ~Message() {removeFromFolders();}
  Message &operator=(const Message &m);
  void save(Folder &f);
  void remove(Folder &f);

private:
  std::string contents;
  std::set<Folder *> folders;
  void addToFolders(const Message &m);
  void removeFromFolders();
};

class Folder
{

public:
  Folder() = default;
  void addMsg(const Message *pmg);
  void remMsg(const Message *pmg);
private:
  std::set<Message *> messages;

};
#endif