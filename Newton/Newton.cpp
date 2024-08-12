#include <iostream>
#include <iomanip>

int main()
{
	double x0 = 0.9;
	double epsilon = 1.0e-14;
	#define f(x) (pow(4.0, x) + pow(6.0, x) - 9.0)
	double x1, y0, y1, m;
	char chr;
	y0 = f(x0);

	for (;;)
	{
		m = (f(x0 * (1.0 + 1.0e-6)) - f(x0)) / (x0 * (1.0 + 1.0e-6) - x0);
		x1 = x0 - y0 / m;
		y1 = f(x0);
		std::cout << std::scientific << std::setprecision(14) << std::showpos;
		std::cout << "X0: " << x0 << "     Y0: " << y0 << "     M: " << m << "     X1 : " << x1 << "     Y1 : " << y1 << std::endl;
		if (abs(x0 - x1) < 0.0001) break;
		x0 = x1;
		y0 = y1;
	}
}
