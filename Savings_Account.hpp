#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "Account.hpp"

class Savings_Account : public Account
{
private:
    const std::string account_type = "Savings Account";
protected:
    double interest;
    virtual bool deposit(double amount)override;
    virtual bool withdraw(double amount)override;
public:
    Savings_Account(std::string account_holder = "Unnamed", double balance = 0.0, double interest = 0.0);
    virtual ~Savings_Account() = default;
    virtual std::string get_account_type()const override{return account_type;}
    virtual double get_interest()const override{return interest;}
    virtual std::string get_holder_name()const override{return account_holder;}
    virtual std::string get_account_number()const override{return account_number;}
    virtual int get_pin()override{return pin;}
};

#endif // SAVINGS_ACCOUNT_HPP
