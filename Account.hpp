#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "Transaction.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>

class Account
{
private:
    const std::string account_type = "Account";
    const double interest = 0.0;
protected:
    int pin;
    std::string account_holder;
    double balance;
    std::string account_number;
    std::vector<Transaction> transactions;
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
public:
    Account(std::string account_holder = "Unnamed", double balance = 0.0);
    virtual ~Account() = default;
    void display();
    void money_transaction(std::string description = "No description", double amount = 0.0);
    virtual std::string get_account_type()const{return account_type;}
    virtual double get_interest()const{return interest;}
    virtual std::string get_holder_name()const{return account_holder;}
    virtual std::string get_account_number()const{return account_number;}
    virtual int get_pin(){return pin;}
};

#endif // ACCOUNT_HPP
