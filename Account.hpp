#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <random>

class Account
{
private:
    const std::string account_type = "Account";
protected:
    std::string account_holder;
    double balance;
    std::string account_number;
public:
    Account(std::string account_holder = "Unnamed", double balance = 0.0);
    ~Account();
    bool deposit(double amount);
    bool withdraw(double amount);
    void display();
};

#endif // ACCOUNT_HPP
