#include "Rates.hpp"

namespace dauphine
{
    Rates::Rates()
    {
    }
    double Rates::getRate(double dx, double dt, double rate)
    {
        return rate; // fonction � changer selon le mod�le utilis�, retourne une constante dans notre cas
    }
    Rates::~Rates()
    {
    }
}
