#include "Transaction.hpp"

Transaction::Transaction(std::string description, double amount)
:description{description}, amount{amount}
{
    std::time_t current_time = std::time(nullptr); //current time in seconds since 1970.
    std::tm* timeinfo = std::localtime(&current_time); //coverting it to time structure
    std::ostringstream oss;
    oss << std::put_time(timeinfo, "%d-%m-%Y"); //formating it and putting to string stream
    std::string current_date = oss.str();
    date = current_date;
}

Transaction::~Transaction(){}

