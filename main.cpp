#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include "closed_form.hpp"
#include "Solver.hpp"
#include "Parameters.hpp"
#include "Grille.hpp"
#include "Boundaries.hpp"
#include "Payoffs.hpp"



//    double payoff(double x) {
//        return std::max(x-100, 0.);
//    }



    std::vector<double> essai()
    {
        double spot;
        double strike;
        double volatility;
        double maturity;
        double rate;
        double theta;
        int cp;
        
        std::cout << "Underlying Spot Price:" << std::endl;
        std::cin >> spot;
        std:: cout << "Strike Price:" << std::endl;
        std::cin >> strike;
        std::cout << "Volatility:" << std::endl;
        std::cin >> volatility;
        std::cout << "Risk free rate:" << std::endl;
        std::cin >> rate;
        std::cout << "Maturity (in years):" << std::endl;
        std::cin >> maturity;
        std::cout << "Theta:" << std::endl;
        std::cin >> theta;
        std::cout << "1.Call /n2.Put:" << std::endl;
        std::cin >> cp;
        bool istrue = true;
		/*
		//COEF POUR NEUMAN
	double ATheta(Grille mesh, Parameters param, bool isright) {
			if (isright == false) {
				return (1. + param.GetTheta()*mesh.getdt()*(-0.5*pow(param.GetVol(), 2) / pow(mesh.getdx()[0], 2) + param.GetRate() - 0.5 * (pow(param.GetVol(), 2) - param.GetRate()))) ;
			}
			else {
				return (1. + (param.GetTheta() - 1.)*mesh.getdt()*(-0.5*pow(param.GetVol(), 2) / pow(mesh.getdx()[0], 2) + param.GetRate() - 0.5 * (pow(param.GetVol(), 2) - param.GetRate())));
			}
		
	}
	double BTheta(Grille mesh, Parameters param, bool isright) {
		if (isright == false) {
			return (param.GetTheta()*mesh.getdt()*(pow(param.GetVol(), 2) / pow(mesh.getdx()[0], 2) + 0.5 *(pow(param.GetVol(), 2) - param.GetRate())/ mesh.getdx()[0]));
		}
		else {
			return ((param.GetTheta() - 1.)*mesh.getdt()*(pow(param.GetVol(), 2) / pow(mesh.getdx()[0], 2) + 0.5 *(pow(param.GetVol(), 2) - param.GetRate()) / mesh.getdx()[0]));
		}
	}
	

	double CTheta(Grille mesh, Parameters param, bool isright) {
		if (isright == false) {
			return (param.GetTheta()*mesh.getdt()*(-0.5*pow(param.GetVol(), 2) / pow(mesh.getdx()[0], 2)));
		}
		else {
			return ((param.GetTheta() - 1.)*mesh.getdt()*(-0.5*pow(param.GetVol(), 2) / pow(mesh.getdx()[0], 2)));
		}
	}
	//FIN COEF NEUMAN;	
		*/
        
        dauphine::Parameters param(volatility, rate, theta);
		
		//test pour un dx fixé en prenant comme frontiere spot +- 5stddev racine T. On centre sur le spot.
        dauphine::Grille mesh(maturity, spot, volatility, (1. / 252.), 1000, 0.2);
        
        //dauphine::Boundaries bound;
        std::vector<double> solution;
        
      　if (cp == 1){
            dauphine::Boundaries bound(mesh, param, strike, dauphine::Payoffs::call);
            solution = dauphine::solving(param,  mesh,  bound);
            solution.push_back(dauphine::bs_price(spot, strike, volatility, maturity, istrue));
            //solution.push_back(temp[0]);
            //solution.push_back(temp[1]);
            //solution.push_back(temp[2]);
            //solution.push_back(temp[3]);
        }
        else if(cp == 2){
            dauphine::Boundaries bound(mesh, param, strike, dauphine::Payoffs::put);
            solution = dauphine::solving(param,  mesh,  bound);
            solution.push_back(0.000);
        }
        
            /*
            std::vector<double> temp = dauphine::solving(param,  mesh,  bound);
            solution.push_back(temp[0]);
            solution.push_back(temp[1]);
            solution.push_back(temp[2]);
            solution.push_back(temp[3]);
        }
        else{
            dauphine::Boundaries bound(mesh, param, strike, dauphine::Payoffs::getThePayoff);
            std::vector<double> temp = dauphine::solving(param,  mesh,  bound);
            solution.push_back(temp[0]);
            solution.push_back(temp[1]);
            solution.push_back(temp[2]);
            solution.push_back(temp[3]);
        }*/
        //dauphine::Boundaries bound(mesh, param, strike, dauphine::Payoffs::getThePayoff); // en dernier paramètre on prend la fonction statique du payoff

        //dauphine::Boundaries bound(mesh, param, strike, dauphine::Payoffs::getThePayoff); // en dernier paramètre on prend la fonction statique du payoff  

		
        /*//test
        std::vector<double> avantdernier(mesh.getTimeNumber());
		//
		std::vector<double> price = dauphine::CrankNicholson(mesh, param, bound, avantdernier);
		std::vector<double> payoff = bound.getpayoff();
		std::vector<double> stock = mesh.getStockVector();
		price.push_back(bound.getupercondition()[mesh.getTimeNumber() - 1]);
		price.insert(price.begin(), bound.getlowercondition()[mesh.getTimeNumber() - 1]);

		//test
		avantdernier.push_back(bound.getupercondition()[mesh.getTimeNumber() - 2]);
		avantdernier.insert(avantdernier.begin(), bound.getlowercondition()[mesh.getTimeNumber() - 2]);
		//test avec adresse

		
		std::vector<double> solution(5);
        
		//on cherche l'index pour lequel on veut le prix
		auto iter = std::find(stock.begin(), stock.end(), spot);
		size_t index = std::distance(stock.begin(), iter);
		//on le met dans un vecteur
		solution[0]= price[index];
		solution[1] = (price[index + 1] - price[index - 1]) / (stock[index + 1] - stock[index - 1]);
		solution[2] = (price[index + 1] - 2*price[index] + price[index - 1]) / (pow((stock[index + 1] - stock[index]),2));
		solution[3] = (avantdernier[index] - price[index]) / (1);
		
		for (std::size_t i = index-10; i < index+10; i++)
		{
			std::cout << stock[i] << " : " << price[i] << std::endl;
		}*/
        
        //std::vector<double> solution = dauphine::solving(param,  mesh,  bound);
                                    
        //solution.push_back(dauphine::bs_price(spot, strike, volatility, maturity, istrue));
        solution.push_back(spot); // a modif
		return solution;
        
		/*std::vector<double> coef = dauphine::Mid_diag_coeff(mesh, param, false);
		for (std::size_t i = 0; i < 50; i++)
		{
			std::cout << stock[i] << " : " << coef[i] << std::endl;
		}*/
	}

//}

int main(int argc, char* argv[])
{
	std::vector<double> solution = essai();
    if(solution[4]!= 0.000){
        std::cout << "BS Price is:"<< solution[4] << std::endl;
    }
    else {
        std::cout << "BS Price is not available for this product" << std::endl;
    }

	std::cout << "Nicholson Price for S = "<< solution[5] << " is : " << solution[0] << std::endl;
	std::cout << "The Delta is " << solution[1] << std::endl;
	std::cout << "The Gamma is " << solution[2] << std::endl;
	std::cout << "The Theta is " << solution[3] <<std::endl;
    return 0;
}
