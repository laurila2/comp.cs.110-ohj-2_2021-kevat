#include "cards.hh"

Cards::Cards() : size_(0), top_(nullptr), bottom_(nullptr) {}

void Cards::add(int id)
{
    CardData *new_card = new CardData;
    new_card->id = id;
    new_card->next = top_;

    if (size_ > 0)
    {
        top_->prev = new_card;
    }

    top_ = new_card;

    ++size_;
    if (size_ == 1)
    {
        bottom_ = top_;
    }
}

void Cards::print_from_top_to_bottom(std::ostream &s)
{
    int juokseva_numero = 1;
    CardData *current = top_;
    while (current != nullptr)
    {
        s << juokseva_numero << ": " << current->id << std::endl;
        ++juokseva_numero;
        current = current->next;
    }
}

bool Cards::remove(int &id)
{
    if (size_ == 0)
    {
        return false;
    }

    id = top_->id;
    CardData *second = top_->next;

    delete top_;
    top_ = second;
    if (top_ != nullptr)
    {
        top_->prev = nullptr;
        second->prev = nullptr;
    }

    --size_;

    if (size_ == 0)
    {
        bottom_ = nullptr;
    }

    return true;
}

bool Cards::bottom_to_top()
{
    if (size_ <= 1)
    {
        return false;
    }
    CardData *old_top = top_;
    CardData *old_bottom = bottom_;

    bottom_ = old_bottom->prev;

    old_bottom->prev->next = nullptr;
    old_bottom->next = old_top;
    old_bottom->prev = nullptr;

    old_top->prev = old_bottom;

    top_ = old_bottom;

    return true;
}

bool Cards::top_to_bottom()
{
    if (size_ <= 1)
    {
        return false;
    }

    CardData *old_top = top_;
    CardData *old_bottom = bottom_;

    top_ = old_top->next;

    old_top->prev = old_bottom;
    top_->prev = nullptr;

    old_bottom->next = old_top;

    bottom_ = old_top;
    old_top->next = nullptr;

    return true;
}

void Cards::print_from_bottom_to_top(std::ostream &s)
{
    int i = 1;
    CardData *current = bottom_;
    while (current != nullptr)
    {
        s << i << ": " << current->id << std::endl;
        ++i;
        current = current->prev;
    }
}

Cards::~Cards()
{
    CardData *current = top_;
    while (current != nullptr)
    {
        CardData *tmp = current->next;
        delete current;
        current = tmp;
    }
}
