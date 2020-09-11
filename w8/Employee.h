#pragma once
#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: w8
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/


#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sdds {

	class Employee {
	public:
                virtual ~Employee() = default;
		virtual void setSalary(double) = 0;
		virtual void bonus() = 0;
		virtual bool workHours() = 0;
		virtual ostream& display(ostream& os) const = 0;
	};
}

#endif
