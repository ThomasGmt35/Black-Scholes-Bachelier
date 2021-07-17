#include <iostream>

#include <iostream>
#include <string>
#include <random>

#include <random>
#include "math.h"
#include <algorithm>
#include "BlackScholesModel.h"
#include "ForwardContract.h"
#include "VanillaEuropeanOption.h"
#include "BlackScholesEulerSimulator.h"
#include "BlackScholesExactSimulator.h"

#include "ExplicitScheme.h"

using namespace std; 

int main()
{

	double S0 = 107;
	double mu = 0.02;
	double r = mu;
	double sigma = 0.15;
		
	double T = 1; 
	double F = S0 * exp(mu * T); 

	double K = F; 

	//K = 0.; 

	// analytical price; 
	BlackScholesModel BS(S0, mu, r, sigma);

	long long_or_short_forward = 1;

	double ITM = 1.2; 
	
	K = ITM * F; 

	double forward_price_analytical = BS.forwardPrice(long_or_short_forward, T, K);

	double price_forward_analytical = 0;
	
	price_forward_analytical = BS.forwardPrice(long_or_short_forward, T, K);
	double price_forward_numerical = 0; 

	int num_steps = 10;
	int num_states = 100;


	cout << "Forward Analytical Price: \n\n";
	cout << price_forward_analytical << "\n\n";
	
	double price_option_analytical = 0;

	long cp = 1; 
	price_option_analytical = BS.vanilla_european_option_price(cp, T, K);

	double price_option_numerical = 0;

	cout << "\n\n";
	cout << "Option analytical price: \n\n";
	cout << price_option_analytical << "\n\n"; 

	return 0;
}
