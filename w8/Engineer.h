/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: w8
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/


#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Employee.h"

using namespace std;

namespace sdds {
	const int MIN_HOURS = 5;
	const int MAX_LEVEL = 4;

	class Engineer : public Employee {
	protected:
		double m_esalary;
		int m_ewhours;
		int m_level;
	public:
		Engineer();
		Engineer(double, int, int);
		void setSalary(double);
		bool workHours();		void bonus();		ostream& display(ostream& os) const;
	};
}

#endif

#pragma once
