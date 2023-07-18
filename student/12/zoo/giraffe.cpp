#include "giraffe.hh"

Giraffe::Giraffe() : Animal("Kip kop kip kop") {}

void Giraffe::suckle(std::ostream &output) const
{
    output << "Mus mus" << std::endl;
}

void Giraffe::make_noise(std::ostream &output)
{
    output << "Ori ori ori!" << std::endl;
}
