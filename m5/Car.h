#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 5
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
#ifndef SDDS_Car_H__
#define SDDS_Car_H__
#include "Vehicle.h"
#include <iostream>
using namespace std;
namespace sdds
{
	class Car : public Vehicle
	{
		bool carwash = false;
	public:
		//A default constructor. calls one-parameter constructor 
		//from the base, and pass 'P' for the record tag
		Car();
		Car(const char lp[], const char* mdl);
		//override for the read() function from the base class
		std::istream& read(std::istream& in);
		//override for the write() function from the base class
		std::ostream& write(std::ostream& os) const;
	};
}


#endif