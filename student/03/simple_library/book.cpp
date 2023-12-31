#include "book.hh"

#include<iostream>

Book::Book(const std::string &author_name, const std::string &title) :
    AUTHOR_NAME_(author_name),
    TITLE_(title),
    is_loaned_(false),
    loan_date_(Date()),
    expiry_date_(Date())

{

}

void Book::print()
{
    std:: cout << AUTHOR_NAME_ << " : " << TITLE_ << std::endl;
    if (is_loaned_)
    {
        std::cout << "- loaned: ";
        loan_date_.print();
        std::cout << "- to be returned: ";
        expiry_date_.print();
    }
    else
    {
        std::cout << "- available" << std::endl;
    }
}

void Book::loan(const Date &loan_date)
{
    if (is_loaned_)
    {
        std::cout << "Already loaned: cannot be loaned" << std::endl;
        return;
    }
    is_loaned_ = true;
    loan_date_ = loan_date;
    expiry_date_= loan_date;
    expiry_date_.advance(LOAN_PERIOD_DAYS);
}

void Book::renew()
{
    if (!is_loaned_)
    {
        std::cout << "Not loaned: cannot be renewed" << std::endl;
        return;
    }

    expiry_date_.advance(LOAN_PERIOD_DAYS);
}

void Book::give_back()
{
    is_loaned_ = false;
}
