#pragma once

#include <iostream>
#include <cstdlib>  // Pour strtod, atoi
#include <cmath>    // Pour floor, isnan (non-standard en C++98)
#include <limits>   // Pour numeric_limits
#include <iomanip>  // Pour setprecision
#include <cctype>   // Pour isprint

class ScalarConverter {

	private :

		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter& operator=(ScalarConverter const &assign);

		~ScalarConverter();
	
	public :

		static void convert(const std::string& input);
};