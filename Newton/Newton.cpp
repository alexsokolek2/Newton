#include <iostream>
#include <iomanip>
#include <math.h>

int main()
{
	double x0 = 0.9;
	double epsilon = 1.0e-14;
	#define f(x) (pow(4.0, x) + pow(6.0, x) - 9.0)
	#define dydx(x) (pow(4.0, x) * log(4.0) + pow(6.0, x) * log(6.0))
	double x1, y0, y1, m;
	char chr;
	y0 = f(x0);

	std::cout << std::scientific << std::setprecision(14) << std::showpos;

	for (;;)
	{
		m = dydx(x0);
		x1 = x0 - y0 / m;
		y1 = f(x0);
		std::cout <<    "X0: "  << x0;
		std::cout << "   Y0: "  << y0;
		std::cout << "   M: "   << m;
		std::cout << "   X1 : " << x1;
		std::cout << "   Y1 : " << y1;
		std::cout << std::endl;
		if (abs(x0 - x1) < 0.0001) break;
		x0 = x1;
		y0 = y1;
	}
	return 0;
}
