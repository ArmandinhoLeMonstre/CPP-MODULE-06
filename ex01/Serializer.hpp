/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:28:51 by armitite          #+#    #+#             */
/*   Updated: 2025/04/18 15:28:52 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <stdint.h>

class Serializer {

	private :

		Serializer();
		Serializer(Serializer const &copy);
		Serializer& operator=(Serializer const &assign);

		~Serializer();
	
	public :

		  static uintptr_t serialize(Data* ptr);

		  static Data* deserialize(uintptr_t raw);
};