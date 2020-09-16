#include <ex13_34.h>

void Message::save(Folder &f)
{
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f)
{
  folders.erase(&f);
  f.remMsg(this);
}

void Message::addToFolders(const Message &m)
{
  for (auto f : m.folders)
    f->addMsg(this);
}
void Message::removeFromFolders()
{
  for (auto f : folders)
    f->remMsg(this);
}

Message &Message::operator=(const Message &m)
{
  removeFromFolders();
  folders = m.folders;
  contents = m.contents;
  addToFolders(m);
  return *this;
}

void swap(Message &lhs, Message &rhs)
{
  using std::swap;
  lhs.removeFromFolders();
  rhs.removeFromFolders();
  swap(lhs.contents, rhs.contents);
  swap(lhs.folders, rhs.folders);
  lhs.addToFolders(lhs);
  rhs.addToFolders(rhs);
}
