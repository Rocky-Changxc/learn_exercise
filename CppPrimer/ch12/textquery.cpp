/*
 * @Author: your name
 * @Date: 2020-09-13 12:32:18
 * @LastEditTime: 2020-09-13 20:41:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Linux_vm\CppPrimer\ch12\textquery.cpp
 */
#include "textquery.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
static void runQueries(ifstream &infile);

int main(void)
{
  ifstream ifs("file.txt");
  runQueries(ifs);
  return 0;
}

ostream &print(ostream &os, const QueryResult &qr)
{
  os << qr.sought << " occurs " << qr.lines->size() << " times" << endl;
  for (auto &line : *qr.lines)
    os << "line " << line + 1 << "\t:" << (*qr.file)[line] << endl;
  return os;
}

static void runQueries(ifstream &infile)
{
  TextQuery tq(infile);

  while (true)
    {
      cout << "enter word to look for, or q to quit: ";
      string s;
      if (!(cin >> s) || s == "q")
        break;
      print(cout, tq.query(s)) << endl;
    }
}

TextQuery::TextQuery(ifstream &infile) : file(new vector<string>)
{
  string line;
  while (getline(infile, line))
    {
      file->push_back(line);
      line_no n = file->size() - 1;

      istringstream iss(line);
      string word;
      while (iss >> word)
        {
          auto &line_nums = wm[word];
          if (!line_nums)
            line_nums.reset(new set<line_no>);
          line_nums->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &word) const
{
  static shared_ptr<set<line_no>> nodata(new set<line_no>);
  auto loc = wm.find(word);
  if (loc == wm.end())
    return QueryResult(word, nodata, file);
  else
    return QueryResult(word, loc->second, file);
}