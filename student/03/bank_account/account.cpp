#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit) :
    OWNER_(owner),
    credit_(has_credit)
{
    generate_iban();
}

void Account::take_money(int amount)
{
    if ( amount > balance_ && !credit_ )
    {
        std::cout << "Cannot take money: balance underflow" << std::endl;
        return;
    }
    else if ( (amount > balance_ + credit_limit_) && credit_ )
    {
        std::cout << "Cannot take money: credit limit overflow" << std::endl;
        return;
    }
    else if ( amount < (balance_ + credit_limit_) && credit_ )
    {
        balance_ -= amount;
        std::cout << amount << " euros taken: new balance of " << iban_ << " is "  << balance_ << " euros" << std::endl;
        return;
    }
    else
    {
        balance_ -= amount;
        std::cout << amount << " euros taken: new balance of " << iban_ << " is "  << balance_ << " euros" << std::endl;
        return;
    }
}

void Account::save_money(int amount)
{
    balance_ += amount;
}

void Account::transfer_to(Account& money_to, int amount)
{
    if ( (amount > balance_ + credit_limit_) && credit_ )
    {
        std::cout << "Cannot take money: credit limit overflow" << std::endl;
        std::cout << "Transfer from " << iban_ << " failed " << std::endl;
        return;
    }
    else if ( (amount < (balance_ + credit_limit_)) && credit_ )
    {
        take_money(amount);
        money_to.save_money(amount);
        return;
    }
    else if (amount > balance_)
    {
        std::cout << "Cannot take money: balance underflow " << std::endl;
        std::cout << "Transfer from " << iban_ << " failed " << std::endl;
        return;
    }
    else
    {
        take_money(amount);
        money_to.save_money(amount);
        return;
    }
}

void Account::set_credit_limit(int credit_limit)
{
    if (credit_ == false)
    {
        std::cout << "Cannot set credit limit: the account has no credit card " << std::endl;
        return;
    }
    else
    {
        credit_limit_ = credit_limit;
    }
}

void Account::print() const
{
    std::cout << OWNER_ << " : " << iban_ << " : " << balance_ << " euros" << std::endl;
}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
