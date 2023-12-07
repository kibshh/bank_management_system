#include "Account.hpp"

Account::Account(std::string account_holder, double balance)
:account_holder{account_holder}, balance{balance}
{
    std::random_device rnd_num; //seeding the random number generator
    std::mt19937 gen(rnd_num()); //seeding the random engine    
    std::uniform_int_distribution<char> distribution('0', '9');
    char cipher = distribution(gen);
    account_number += cipher;
    for(size_t i{0}; i<22; i++)
    {
        char cipher = distribution(gen);
        account_number += cipher;
        if(i == 7 || i == 17)
            account_number += '-';
    }
}

Account::~Account(){}

bool Account::deposit(double amount)
{
    if(amount < 0)
    {
        return false;
    }
    else
    {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount)
{
    if(balance < amount)
    {
        return false;
    }
    else
    {
        balance -= amount;
        return true;
    }
}

void Account::display()
{
    std::cout<<std::setw(45)<<std::setfill('-')<<"-"<<std::setfill(' ')<<std::endl;
    std::cout<<std::setw(10)<<" "<<"Account Information"<<std::endl;
    std::cout<<std::setw(45)<<std::setfill('-')<<"-"<<std::setfill(' ')<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Account Type:"<<account_type<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Account Number:"<<account_number<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Account Holder:"<<account_holder<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Balance:"<<"$"<<balance<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Available:"<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Interest Rate:"<<std::endl;
    std::cout<<std::setw(45)<<std::setfill('-')<<"-"<<std::setfill(' ')<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Recent Transactions:"<<std::endl;
    std::cout<<std::setw(45)<<std::setfill('-')<<"-"<<std::setfill(' ')<<std::endl;
    std::cout<<std::setw(11)<<std::left<<"Date"<<std::setw(23)<<std::left
    <<"Description"<<std::setw(11)<<std::left<<"Amount"<<std::endl;
    std::cout<<std::setw(45)<<std::setfill('-')<<"-"<<std::setfill(' ')<<std::endl;

}

