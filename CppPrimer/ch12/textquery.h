/*
 * @Author: your name
 * @Date: 2020-09-13 12:32:30
 * @LastEditTime: 2020-09-13 20:40:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Linux_vm\CppPrimer\ch12\textquery.h
 */
#ifndef __TEXTQUERY_H
#define __TEXTQUERY_H

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <vector>
class QueryResult;
std::ostream &print(std::ostream &, const QueryResult &);
class TextQuery
{
public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &);
  QueryResult query(const std::string &) const;

private:
  std::shared_ptr<std::vector<std::string>> file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult
{
  using line_no = std::vector<std::string>::size_type;
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  QueryResult(std::string s, std::shared_ptr<std::set<line_no>> lset,
              std::shared_ptr<std::vector<std::string>> fvec) :
              sought(s), lines(lset), file(fvec){}

private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;
};

#endif