#include <iostream>

int main()
{
	double xleft = 0.9;
	double xright = 1.0;
	double epsilon = 0.00000000000001;
	#define f(x) (pow(4.0, x) + pow(6.0, x) - 9.0)
	double x, y, m;

	while (xleft * (1.0 + epsilon) < xright)
	{
		m = (f(xleft * (1.0 + epsilon)) - f(xleft)) / (xleft * (1.0 + epsilon) - xleft);

	}
}
