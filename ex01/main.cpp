/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:28:44 by armitite          #+#    #+#             */
/*   Updated: 2025/04/18 15:28:45 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data data;
    data.age = 27;
    data.name = "Guest";

    uintptr_t raw = Serializer::serialize(&data);

    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &data) {
        std::cout << "Serialization successful!" << std::endl;
        std::cout << "Data content: " << ptr->age << ", " << ptr->name << std::endl;
    } else {
        std::cout << "Serialization failed!" << std::endl;
    }

    return 0;
}