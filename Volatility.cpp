#include "Volatility.hpp"

namespace dauphine
{
    Volatility::Volatility()
    {
    }
    double Volatility::getVolatility(double dx, double dt, double volatility)
    {
        return volatility; // fonction � changer selon le modele utilise, retourne une constante dans notre cas
    }
    Volatility::~Volatility()
    {
    }
}
