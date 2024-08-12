#include <iostream>

int main()
{
	double x0 = 0.9;
	double epsilon = 0.00000000000001;
	#define f(x) (pow(4.0, x) + pow(6.0, x) - 9.0)
	double x1, y1, m, b;

	while (xleft * (1.0 + epsilon) < xright)
	{
		yleft = f(xleft);
		m = (f(xleft * (1.0 + epsilon)) - yleft) / (xleft * (1.0 + epsilon) - xleft);
		b = yleft - m * xleft;
		x = -b / m;
		y = f(x);

	}
}
