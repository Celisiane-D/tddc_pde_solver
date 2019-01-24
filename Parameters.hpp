#ifndef Parameters_HPP
#define Parameters_HPP

#include <vector>

namespace dauphine
{
	//D�finition des param�tres qu'on prend en input, rajouter une classe vol et une classe rate avec des h�ritages pour bien sp�cifier, A FAIRE.
	class Parameters {
	public:
		Parameters(double volatility, double rate, double theta);
		double GetVol() const;
		double GetRate() const;
		double GetTheta() const;
		~Parameters();

	private:
		//std::vector <double> param;
		double m_volatility;
		double m_rate;
		double m_theta;
	};
}


#endif
