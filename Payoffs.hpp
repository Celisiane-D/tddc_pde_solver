#ifndef Payoffs_hpp
#define Payoffs_hpp

#include <iostream>

namespace dauphine
{
    class Payoffs {
    public:
        Payoffs();
        static double getThePayoff(double spot, double strike); // fonction statique pour �viter de cr�er un objet payoff, utile pour mettre en param�tre dans l'objet boundaries
        static double call(double spot, double strike);
        static double put(double spot, double strike);
        ~Payoffs();
        
    private:
//        double Strike;
//        double Spot;
    };
}

#endif /* Payoffs_hpp */

