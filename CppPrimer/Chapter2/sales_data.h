#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

class Sales_data
{
  friend istream &read(istream &, Sales_data &);
  friend ostream &print(ostream &, const Sales_data &);
  friend Sales_data add(const Sales_data &, const Sales_data &);
  public:
    Sales_data() = default; /* c++11特性 */
    Sales_data(const string &bn) : bookNo(bn) {}
    Sales_data(const string &bn, unsigned us, double price) : 
                bookNo(bn), unit_sold(us), revenue(us * price) {}
    Sales_data(istream &is);
    
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &temp);
    inline double avg_price() const;

  private:
    string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, const Sales_data &);
istream &read(istream &, Sales_data &);

Sales_data& Sales_data::combine(const Sales_data& temp)
{
  revenue += temp.revenue;
  unit_sold += temp.unit_sold;
  return *this;
}

inline double Sales_data::avg_price() const
{
  // if (unit_sold)
  //   return revenue/unit_sold;
  // return 0;
  return unit_sold? revenue/unit_sold : 0;
}

istream &read(istream &is, Sales_data &sd)
{
  // cout << "Input bookNo, unitsold, price" << endl;
  double price;
  is >> sd.bookNo >> sd.unit_sold >> price;
  sd.revenue = sd.unit_sold * price;
  return is;
}

ostream &print(ostream &out, const Sales_data &sd)
{
  out << "bookNo:" + sd.bookNo << " " 
      << "unit_sold:" << sd.unit_sold << " "
      << "revenue:" << sd.revenue << " " 
      << "avg_price:" << sd.avg_price();
  return out;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data res;
  res = lhs;
  res.combine(rhs);
  return res;
}

#endif