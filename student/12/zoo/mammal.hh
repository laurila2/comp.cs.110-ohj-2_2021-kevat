#ifndef MAMMAL_HH
#define MAMMAL_HH
#include "animal.hh"

class Mammal : public Animal
{
public:
    Mammal();
    void suckle(std::ostream &output);
    void move(int x, int y, std::ostream &output);
    void print_location(std::ostream &output) const;

private:
    int x_;
    int y_;
    std::string moving_noise_;
};

#endif // MAMMAL_HH
