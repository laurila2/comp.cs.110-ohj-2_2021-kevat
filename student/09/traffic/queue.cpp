#include "queue.hh"
#include <iostream>
#include <string>

Queue::Queue(unsigned int cycle) : cycle_(cycle) {}

Queue::~Queue()
{
    while (first_ != nullptr)
    {
        Vehicle *auton_muisti = first_;
        first_ = first_->next;
        delete auton_muisti;
    }
}

void Queue::enqueue(string reg)
{
    if (!is_green_)
    {
        Vehicle *uusi_auto = new Vehicle{reg, nullptr};

        if (first_ == nullptr)
        {
            first_ = uusi_auto;
            last_ = uusi_auto;
        }
        else
        {
            last_->next = uusi_auto;
            last_ = uusi_auto;
        }
    }
    else
    {
        std::cout << "GREEN: The vehicle " << reg << " need not stop to wait"
                  << std::endl;
    }
}

void Queue::switch_light()
{
    is_green_ = !is_green_;

    Vehicle *auto_poistettavaksi = first_;
    Vehicle *auto_poistettavaksi_old = first_;

    if (is_green_) // GREEN LIGHT
    {
        if (!is_empty())
        {
            std::cout << "GREEN: Vehicle(s)";

            unsigned j = 0;
            while (j < cycle_)
            {
                std::cout << " " << auto_poistettavaksi->reg_num;
                auto_poistettavaksi = auto_poistettavaksi->next;

                dequeue(auto_poistettavaksi_old->reg_num);

                if (auto_poistettavaksi == nullptr)
                {
                    break;
                }
                auto_poistettavaksi_old = auto_poistettavaksi;
                ++j;
            }

            std::cout << " can go on" << std::endl;

            is_green_ = false;
        }
        else
        {
            std::cout << "GREEN: No vehicles waiting in traffic lights"
                      << std::endl;
        }
    }
    else // RED LIGHT
    {
        print();
    }
}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print()
{
    Vehicle *ajoneuvo_printattavaksi = first_;
    int i = 1;

    if (is_green_)
    {
        std::cout << "GREEN: ";
    }
    else
    {
        std::cout << "RED: ";
    }
    if (!is_empty())
    {
        std::cout << "Vehicle(s)";
        while (ajoneuvo_printattavaksi != nullptr)
        {
            std::cout << " " << ajoneuvo_printattavaksi->reg_num;
            ++i;
            ajoneuvo_printattavaksi = ajoneuvo_printattavaksi->next;
        }

        std::cout << " waiting in traffic lights" << std::endl;
    }
    else
    {
        std::cout << "No vehicles waiting in traffic lights" << std::endl;
    }
}

bool Queue::dequeue(string reg)
{
    if (is_empty())
    {
        return false;
    }
    Vehicle *poistettava_auto = first_;
    reg = poistettava_auto->reg_num;

    if (first_ == last_)
    {
        first_ = nullptr;
        last_ = nullptr;
    }

    else
    {
        first_ = first_->next;
    }

    delete poistettava_auto;

    return true;
}

bool Queue::is_empty()
{
    if (first_ == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
