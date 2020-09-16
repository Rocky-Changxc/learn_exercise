#ifndef ACCOUNT_H
#define ACCOUNT_H

using std::string;
class Account
{
  public:
    Account(const string name, const double amount) : ac_owner(name), amount(amount){}
    void calculate(){ amount += amount * interestRate;}
    static void set_rate(const double rate){ interestRate = rate;}
    double get_amount() { return amount; }
  private:
    static double interestRate;
    static constexpr double a = 1.5;
    string ac_owner;
    double amount;
    static double initRate() { return 0.021; }
};
#endif
