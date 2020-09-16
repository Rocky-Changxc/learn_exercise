#include <vector>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
  vector<pair<string, int>> tvec;
  string s;
  int n;
  while (cin >> s >> n)
    {
      tvec.push_back(pair<string, int>(s, n));
      tvec.push_back({s, n});
      tvec.push_back(make_pair(s, n));
      tvec.emplace_back(s, n); /* easiest way */
    }

}