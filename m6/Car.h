/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 4
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
/*I have done all the coding by myself and only copied the code that my professor
provided to complete this program.*/

#ifndef SDDS_CAR_H__

#define SDDS_CAR_H__



#include <iostream>

#include "Vehicle.h"



namespace sdds {

	class Car : public Vehicle {

		bool carWash;

	public:

		Car(); // A default constructor.calls one - parameter constructor from the base

		Car(const char* plate, const char* makeModel, int spotNum = 0, bool flag = false);

		Car(const Car& cCopy) = delete;

		Car& operator=(const Car& cCopy) = delete;

		virtual std::istream& read(std::istream& istr = std::cin); //override for the read() function from the base class

		virtual std::ostream& write(std::ostream& ostr = std::cout) const; //override for the write() function from the base class

		virtual ~Car();

	};

}

#endif