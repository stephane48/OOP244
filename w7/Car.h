/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: w7
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Vehicle.h"

using namespace std;

namespace sdds {
	
	const int MAX_CHAR = 20;
	const int MIN_YEAR = 2000;

	class Car : public Vehicle {
	protected:
		char m_carType [MAX_CHAR];
		int m_regYear;
	public:
		Car();
		Car(const char*, int, int, int);
		void finetune();
		ostream& display(ostream& os) const;		istream& input(istream& in);
	};
	ostream& operator<<(ostream& os, const Car& C);
	istream& operator>>(istream& in, Car& C);
}

#endif