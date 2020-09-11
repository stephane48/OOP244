/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 5
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
/*I have done all the coding by myself and only copied the code that my professor
provided to complete this program.*/

#ifndef SDDS_MOTORCYCLE_H__

#define SDDS_MOTORCYCLE_H__



#include "Vehicle.h"



namespace sdds {

	class Motorcycle : public Vehicle {

		bool hasSidecar;

	public:

		Motorcycle(); //A default constructor. calls one-parameter constructor from the base

		Motorcycle(const char* plate, const char* makeModel, int spotNum = 0, bool flag = false);

		Motorcycle(const Motorcycle& mCopy) = delete;

		Motorcycle& operator=(const Motorcycle& mCopy) = delete;

		virtual std::istream& read(std::istream& istr = std::cin); //override for the read() function from the base class

		virtual std::ostream& write(std::ostream& ostr = std::cout) const;//override for the write() function from the base class

		virtual ~Motorcycle();

	};

}

#endif