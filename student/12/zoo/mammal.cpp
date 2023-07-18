#include "mammal.hh"

Mammal::Mammal() : Animal("Kip kop kip kop") {}

void Mammal::suckle(std::ostream &output)
{
    output << "Mus mus" << std::endl;
}

void Mammal::move(int x, int y, std::ostream &output)
{
    x_ = x;
    y_ = y;

    output << moving_noise_ << std::endl;
}

void Mammal::print_location(std::ostream &output) const
{
    output << "Location: " << x_ << " " << y_ << std::endl;
}
