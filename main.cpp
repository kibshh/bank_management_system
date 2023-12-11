#include <iostream>
#include <limits>
#include <utility>
#include "Savings_Account.hpp"

#define NUMBER_OF_ACCOUNT_TYPES 1
#define NUMBER_OF_INPUT_OPTIONS 5

Account* create_account();
template<typename T>
T prompt(std::string prompt_message, std::string failed_message);
void clear_input();
void display_menu();

int main()
{
    int input{};
    std::vector<Account*> accounts{};
    
    do
    {
        display_menu();
        
        input = prompt<int>("Enter here: ", "Please enter a valid option: ");
        while(input < 1 || input > NUMBER_OF_INPUT_OPTIONS)
        {
            input = prompt<int>("Enter a valid number: ", "Please enter a valid option: ");
        }
        
        Account *acc;
        bool flag = false;
        std::string acc_holder;
        
        switch(input)
        {
            case 1:
            acc = create_account();
            accounts.push_back(acc);
            break;
            
            case 2:
            std::cout<<"Enter account holder's name: ";
            std::getline(std::cin, acc_holder);
            for(auto a: accounts)
            {
                if(a->get_holder_name() == acc_holder)
                {
                    flag = true;
                    a->display();
                }
            }
            if(!flag)
                std::cout<<"There is no accounts under name "<<acc_holder<<std::endl;
            break;
            
            case 3:
            std::cout<<"Enter account holder's name: ";
            std::getline(std::cin, acc_holder);
            for(auto a: accounts)
            {
                if(a->get_holder_name() == acc_holder)
                {
                    flag = true;
                    double amount = prompt<double>("Enter the amount( + for deposit / - for withdrawal ): $", "Please enter a valid amount: $ ");
                    std::string description;
                    std::cout<<"Description: ";
                    std::getline(std::cin, description);
                    a->money_transaction(description, amount);
                    break;
                }
            }
            if(!flag)
                std::cout<<"There are no accounts under name "<<acc_holder<<std::endl;
            break;
            
            case 4:
            std::cout<<std::setw(55)<<std::setfill('-')<<"-"<<std::setfill(' ')<<std::endl;
            for(auto a: accounts)
            {
                std::cout<<std::setw(27)<<std::left<<a->get_holder_name()<<"   "<<a->get_account_number()<<std::endl;
            }
            std::cout<<std::setw(55)<<std::setfill('-')<<"-"<<std::setfill(' ')<<std::endl;
            break;
            
            case 5:
            std::cout<<"Thank you for using our service!"<<std::endl;
        }
    }while(input != 5);
	return 0;
}

template<typename T>
T prompt(std::string prompt_message, std::string failed_message)
{
    T input;
    std::cout<<prompt_message;
    while(1){
        std::cin>>input;
        if(std::cin.fail() || std::cin.peek() != '\n')
        {
            clear_input();
            std::cout<<failed_message;
        }
        else
        {
            clear_input();
            return input;
        }
    }
}

Account *create_account()
{
    int acc_type{};
    acc_type = prompt<int>("Which account type do you want?\n[1] Savings\n\nEnter your option: ", "Please enter a valid option: ");
    while(acc_type < 1 || acc_type > NUMBER_OF_ACCOUNT_TYPES)
    {
        acc_type = prompt<int>("Enter a valid number: ", "Please enter a valid option: ");
    }
    
    switch(acc_type)
    {
        case 1:
        std::cout<<"Name of the account holder: ";
        std::string acc_holder;
        std::getline(std::cin, acc_holder);
        if (acc_holder.length() > 35)
        {
            std::cout<<"Account holder name exceeds the maximum length. Truncating to ";
            acc_holder = acc_holder.substr(0, 35);
            std::cout<<acc_holder<<std::endl;
        }
        double acc_balance = prompt<double>("Starting balance: $", "Invalid input, please enter a valid balance: $");
        double acc_interest = prompt<double>("Interest rate: ", "Invalid input, please enter a valid interest: ");;
        
        Account *acc = new Savings_Account(acc_holder, acc_balance, acc_interest);
        std::cout<<"Congratulations, "<<acc->get_holder_name()<<", your account is now active."<<std::endl;
        std::cout<<"Your PIN is "<<acc->get_pin()<<std::endl;
        return acc;
        break;
    }
}

void clear_input()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void display_menu()
{
    std::cout<<"\nACCOUNT MANAGEMENT SYSTEM"<<std::endl;
    std::cout<<"Which action do you want?"<<std::endl;
    std::cout<<"[1] Add an account"<<std::endl;
    std::cout<<"[2] Display an account details"<<std::endl;
    std::cout<<"[3] Account Transaction"<<std::endl;
    std::cout<<"[4] Display all the existing accounts"<<std::endl;
    std::cout<<"[5] Exit the program"<<std::endl;
}