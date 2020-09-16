#ifndef SALES_ITEM_H
#define SALES_ITEM_H
using namespace std;
class Sales_item
{
  public:
    string isbn(){return bookNo;}
  private:
    string bookNo;
    double revenue;
};

#endif