// newton.cpp - Finds root of function by using the Newton–Raphson method.
//
// Currently configured to find the root of 4^X + 6^X -9 = 0.
// To configure for other functions, see the two defines.
// Note that in addition to the main function, you need the deriviative.
//
// Only finds one root.This program was written to solve a FaceBook math
// problem, namely solve for x where 4 ^ x + 6 ^ x = 9.
// 
// Microsoft Visual Studio 2022 Community Edition 64 Bit 17.10.5
//
// Alex Sokolek, Version 1.0.0.1, Copyright (c) August 13, 2024
// 
/////////////////////////////////////////////////////////////////////////
//
// BSD 3 - Clause License
//
// Copyright(c) 2024, Alex Sokolek
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met :
// 
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and /or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
///////////////////////////////////////////////////////////////////////

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
		// Calculate slope at x0.
		m = dydx(x0);
		if (m == 0.0)
		{
			std::cout << "ERROR: dydx(" << x0 << ") is zero." << std::endl;
			break;
		}
		
		// Calculate xn+1.
		x1 = x0 - y0 / m;

		// Not needed for the algorithm. Included for diagnostic purposes.
		y1 = f(x1);

		// Output state.
		std::cout <<    "X0: "  << x0;
		std::cout << "   Y0: "  << y0;
		std::cout << "   M: "   << m;
		std::cout << "   X1 : " << x1;
		std::cout << "   Y1 : " << y1;
		std::cout << std::endl;

		// Stop when desired precision is reached.
		if (abs(x0 - x1) < epsilon) break;

		// Iterate, shifting x1,y1 to x0,y0.
		x0 = x1;
		y0 = y1;
	}

	// Display root.
	std::cout << std::endl << "Found one (only) root at " << x0 << std::endl;

	return 0;
}
