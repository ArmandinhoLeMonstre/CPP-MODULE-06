/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:28:17 by armitite          #+#    #+#             */
/*   Updated: 2025/04/18 15:54:55 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isPseudoLiteral(const std::string& s) {
    return (s == "inf" || s == "-inf" || s == "+inf" || 
            s == "nan" || s == "inff" || s == "-inff" || 
            s == "+inff" || s == "nanf");
}

static void printChar(double d) {
    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || !isprint(static_cast<char>(d))) {
        if (d >= 0 && d <= 127 && !isprint(static_cast<char>(d)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    }
}

static void printInt(double d) {
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void printFloat(double d) {
    if (std::isinf(d))
        std::cout << "float: " << (d < 0 ? "-" : "") << "inff" << std::endl;
    else if (std::isnan(d))
        std::cout << "float: nanf" << std::endl;
    else {
        float f = static_cast<float>(d);
        std::cout << "float: " << f;
        (f == static_cast<float>(static_cast<int>(f))) ? std::cout << ".0f" : std::cout << "f";
        std::cout << std::endl;
    }
}

static void printDouble(double d) {
	if (std::isnan(d))
        std::cout << "double: nan";
    else
    {    
        std::cout << "double: " << d;
        (d == static_cast<double>(static_cast<int>(d))) ? std::cout << ".0" : std::cout << "";
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& s) {
    double d;
    char* endPtr;

    if (s.empty()) {
        std::cout << "Error: empty input" << std::endl;
        return;
    }

    if (isPseudoLiteral(s)) {
        if (s == "nan" || s == "nanf") {
            d = std::numeric_limits<double>::quiet_NaN();
        } 
        else if (s[0] == '-') {
            d = -std::numeric_limits<double>::infinity();
        } 
        else {
            d = std::numeric_limits<double>::infinity();
        }
    } 
    else if (s.length() == 1 && !isdigit(s[0])) {
        d = static_cast<double>(s[0]);
    }
    else {
        d = std::strtod(s.c_str(), &endPtr);
        if (*endPtr == 'f') {
            endPtr++;
        }
        if ((*endPtr != '\0')) {
            std::cout << "Error: invalid input format" << std::endl;
            return;
        }
    }

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}