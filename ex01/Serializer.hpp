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