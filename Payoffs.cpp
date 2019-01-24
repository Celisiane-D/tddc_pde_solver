#include "Payoffs.hpp"
#include <algorithm>
namespace dauphine
{
    Payoffs::Payoffs()
    {
    }
    double Payoffs::getThePayoff(double spot, double strike)
    {
        return std::max(spot - strike, 0.); // fonction � adapter selon le payoff, un call dans notre cas
    }
    Payoffs::~Payoffs()
    {
    }
}
