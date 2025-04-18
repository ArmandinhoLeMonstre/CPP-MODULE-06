/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:29:08 by armitite          #+#    #+#             */
/*   Updated: 2025/04/18 16:27:25 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate() 
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    int r = std::rand() % 3;
    if (r == 0) {
        std::cout << "Generated A " << std::endl;
        return new A;
    } else if (r == 1) {
        std::cout << "Generated B " << std::endl;
        return new B;
    } else {
        std::cout << "Generated C " << std::endl;
        return new C;
    }
}

void identify_pointer(Base* p) 
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Type: Unknown\n" << std::endl;
}

void identify_ref(Base& p) 
{
    try {
        A &A_ref = dynamic_cast<A&>(p);
        std::cout << "Type A : " << &A_ref << std::endl;
        return;
    } 
	catch (std::exception &e) {

		std::cout << "Not A, trying B : " << e.what() << std::endl;
	}

    try {
        B &B_ref = dynamic_cast<B&>(p);
        std::cout << "Type B : " << &B_ref << std::endl;
        return;
    } 
	catch (std::exception &e) {

		std::cout << "Not B, trying C : " << e.what() << std::endl;
	}
    try {
        C &C_Ref = dynamic_cast<C&>(p);
        std::cout << "Type C : " << &C_Ref << std::endl;
        return;
    } 
	catch (std::exception &e) {

		std::cout << "Error : " << e.what() << std::endl;
	}

    std::cout << "Type: Unknown" << std::endl;
}

int main() {
    Base* obj = generate();

    std::cout << "identify pointer :" << std::endl;
    identify_pointer(obj);

    std::cout << "identify reference :" << std::endl;
    identify_ref(*obj);

    delete obj;
    return 0;
}
