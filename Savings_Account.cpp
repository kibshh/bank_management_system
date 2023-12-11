#include "Savings_Account.hpp"

Savings_Account::Savings_Account(std::string account_holder, double balance, double interest)
:Account(account_holder, balance), interest{interest}{}

bool Savings_Account::deposit(double amount)
{
    amount += amount * (interest / 100);
    return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount)
{
    return Account::withdraw(amount);
}

