/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: w8
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/


#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Employee.h"

using namespace std;

namespace sdds {
	const int MIN_W_HOURS = 6;
	const int MAX_CHAR = 20;

	class Doctor : public Employee{
	protected:
		char m_type[MAX_CHAR + 1];
		double m_salary;
		int m_whours;
		bool m_specialist;
	public:
		Doctor();
		Doctor(const char*, double, int, bool specialist = false);
		void setSalary(double);
		bool workHours();
		void bonus();
		ostream& display(ostream& os) const;

	};
}

#endif

