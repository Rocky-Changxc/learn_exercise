#include <iostream>
#include <fstream>
#include "../using.h"
#include "../Chapter2/Sales_data.h"

int main(int argc, char **argv)
{
  std::ifstream ifs(argv[1]);
  Sales_data total;
  if (read(ifs, total))
    {
      Sales_data trans;
      while(read(ifs, trans))
        {
          if (total.isbn() == trans.isbn())
            total.combine(trans);
          else
            {
              print(cout, total) << endl;
              total = trans;
            }
        }
      print(cout, total) << endl;
    }
  else
    {
      cerr << "No Data?!" << endl;
      return -1;
    }
  return 0;
}