#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <sstream>
#include <ctime>
#include <iomanip>

class Transaction
{
private:
    std::string date;
    std::string description;
    double amount;
public:
    Transaction(std::string description = "No description", double amount = 0.0);
    ~Transaction();
    std::string get_date(){return date;}
    std::string get_description(){return description;}
    double get_amount(){return amount;}
};

#endif // TRANSACTION_HPP
