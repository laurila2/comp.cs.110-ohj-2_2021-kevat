#ifndef GIRAFFE_HH
#define GIRAFFE_HH

#include "mammal.hh"

class Giraffe : public Animal
{
public:
    Giraffe();
    void suckle(std::ostream &output) const;
    void make_noise(std::ostream &output);
};

#endif // GIRAFFE_HH
