/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:28:20 by armitite          #+#    #+#             */
/*   Updated: 2025/04/18 15:28:34 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>
#include <cctype>

class ScalarConverter {

	private :

		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter& operator=(ScalarConverter const &assign);

		~ScalarConverter();
	
	public :

		static void convert(const std::string& input);
};