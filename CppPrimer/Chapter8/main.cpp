#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

std::istream& getdata(std::istream &is);
void rdfile(const std::string &filename);
void rdfile_word(const std::string &filename);
void fileConvert(string dstFile, string srcFile);

int main()
{
  // getdata(std::cin);
  // rdfile("Chapter8/file8-4.txt"); /* 此处路径需注意，使用\\或/，相对目录为工程相对目录 */
  // rdfile_word("D:/Cxc/MyCode/Code/Chapter8/file8-4.txt");
  fileConvert("Chapter8/file8-5.txt", "Chapter8/file8-4.txt");
  system("pause");
  return 0;
}

/* test */
void fileConvert(string dstFile, string srcFile)
{
  ifstream in(srcFile);
  ofstream out(dstFile);
  string temp;
  while(getline(in, temp))
    {
      out << temp << endl;
    }
}
/* p8.1 */
std::istream& getdata(std::istream &is)
{
  std::string a; /* 初次使用的char，效果应该是一致的 */
  while(is >> a)
    {
      cout << a;
    }
  is.clear();
  return is;
}

/* p8.3
 * badbit, failbit, eofbit即终止
 *  */

/* p8.4 */
void rdfile(const std::string &filename)
{
  std::string s;
  std::vector<std::string> v;

  std::ifstream ifs(filename);
  if (!ifs.is_open())
    cout << "file not open!" << endl;
  while(getline(ifs, s))
    {
      v.push_back(s);
    }
  for (std::string i : v)
    std::cout << i << std::endl;
}

/* p8.5 */

void rdfile_word(const std::string &filename)
{
  std::string s;
  std::vector<std::string> v;

  std::ifstream ifs(filename);
  while(ifs >> s)
    {
      v.push_back(s);
    }
  for (std::string i : v)
    std::cout << i << std::endl;
}