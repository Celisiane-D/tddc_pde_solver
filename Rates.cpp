#include "Rates.hpp"

namespace dauphine
{
    Rates::Rates()
    {
    }
    double Rates::getRate(double dx, double dt, double rate)
    {
        return rate; // fonction � changer selon le modele utilise, retourne une constante dans notre cas
    }
    Rates::~Rates()
    {
    }
}
