/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: w8
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <string.h>
#include "Doctor.h"

using namespace sdds;
using namespace std;
namespace sdds {
	Doctor::Doctor() {
		m_type[0] = '\0';
	        m_salary = 0;
		m_whours = 0;
		m_specialist = false;
	}

	Doctor::Doctor(const char* type, double salary, int whours, bool specialist) {
		if (salary > 0 && whours > 0) {
			strcpy(m_type, type);
			m_whours = whours;
			m_specialist = specialist;
			this->setSalary(salary);
		}
		else {
			*this = Doctor();
		}
	}

	void Doctor::setSalary(double salary) {
		if (m_specialist == true) {
			m_salary = salary + 2000;
		}
		else {
			m_salary = salary;
		}
	}

	bool Doctor::workHours(){
		bool see;
		if (m_whours == MIN_W_HOURS) {
			see = true;
		}
		else {
			see = false;
		}
		return see;
	}

	void Doctor::bonus() {
		double bonus;
		if (m_whours > MIN_W_HOURS) {
			bonus = m_salary * 0.1;
			m_salary += bonus;
		}
		else {
			bonus = m_salary * 0.05;
			m_salary += bonus;
		}
	}

	ostream& Doctor::display(ostream& os) const {
		if (m_type[0] == '\0') {
			os << "Doctor is not initiated yet" << endl;
		}
		else if (m_salary > 0 && m_whours > 0) {
			os << "Doctor details" << endl;
			os << "Doctor Type: " << m_type << endl;
			os << fixed;
			os << setprecision(2);
			os << "Salary: " << m_salary << endl;
			os << "Working Hours: " << m_whours << endl;
		}
		else {
		}
		return os;
	}
}


