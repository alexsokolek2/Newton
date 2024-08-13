// newton.cpp - Finds root of function by using the Newton–Raphson method.
//
// Currently configured to find the root of 4^X + 6^X - 9.
// To configure for other functions, see the two defines.
// Note that in addition to the main function, you need the deriviative.

#include <iostream>
#include <iomanip>

int main()
{
	#define f(x) (pow(4.0, x) + pow(6.0, x) - 9.0)
	#define dydx(x) (pow(4.0, x) * log(4.0) + pow(6.0, x) * log(6.0))
	double x0, y0, x1, y1, m;
	double epsilon = 1.0e-14;
	
	x0 = 0.9; // Initial guess
	y0 = f(x0);

	std::cout << std::scientific << std::setprecision(14) << std::showpos;

	for (;;)
	{
		m = dydx(x0);
		x1 = x0 - y0 / m;
		y1 = f(x1);
		std::cout <<    "X0: "  << x0;
		std::cout << "   Y0: "  << y0;
		std::cout << "   M: "   << m;
		std::cout << "   X1 : " << x1;
		std::cout << "   Y1 : " << y1;
		std::cout << std::endl;
		if (abs(x0 - x1) < epsilon) break;
		x0 = x1;
		y0 = y1;
	}
	return 0;
}
