#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <vector>

namespace dauphine
{//  D�finition du mesh Borne sup et inf du stock, Timenumber et stocknumber = Nombre de "pas", le vecteur sert a rien pour l'instant, plus tard surement pour d�finir les boundaries
//dx et dt correspondent � la taille des step qui sont calcul�s. Peut �tre tout d�finir sous forme de vecteur...?
	//Plein de variables inutiles, je me suis pris la t�te, enlev� Stockmin, Time Number certainement...
	class Grille {
	public:
		Grille(double Time, double StockMax, double StockMin, double dt, double dx);
		std::vector<double> getStockVector() const;
		std::vector<double> getTimeVector() const;
		double getdt() const;
		double getTimeNumber() const;
		double GetTailleStock() const;
		double getdx() const;
		~Grille();

	private:
		double Time;
		double StockMax;
		size_t TimeNumber;
		size_t StockNumber;
		double dt;
		double dx;
		std::vector<double> StockVector;
	};
}

#endif