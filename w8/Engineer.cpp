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
#include "Engineer.h"

using namespace sdds;
using namespace std;
namespace sdds {
	Engineer::Engineer() {
		m_esalary = 0;
		m_ewhours = 0;
		m_level = 0;
	}

	Engineer::Engineer(double esalary, int ewhours, int level) {
		if (esalary > 0 && ewhours > 0 && level > 0) {
			m_level = level;
			m_ewhours = ewhours;
			this->setSalary(esalary);
		}
		else
		{
			*this = Engineer();
		}
	}

	void Engineer::setSalary(double esalary) {
		if (m_level == MAX_LEVEL) {
			/*esalary += 3000;*/
			m_esalary = esalary + 3000;
		}
		else {
			m_esalary = esalary;
		}
	}
	
	bool Engineer::workHours() {
		bool see;
		if (m_ewhours == MIN_HOURS) {
			see = true;
		}
		else {
			see = false;
		}
		return see;
	}

	void Engineer::bonus() {
		double bonus;
		if (m_ewhours > MIN_HOURS && m_level == MAX_LEVEL) {
			bonus = m_esalary * 0.1;
			m_esalary += bonus;
		}
		else {
			bonus = m_esalary * 0.05;
			m_esalary += bonus;
		}
	}

	ostream& Engineer::display(ostream& os) const {
		if (m_esalary <= 0 && m_ewhours <= 0 && m_level <= 0) {
			os << "Engineer is not initiated yet" << endl;
		}
		else if (m_esalary > 0 && m_ewhours > 0) {
			os << "Engineer details" << endl;
			os << "level: " << m_level << endl;
			os << fixed;
			os << setprecision(2);
			os << "Salary: " << m_esalary << endl;
			os << "Working hours: " << m_ewhours << endl;
		}
		else {
		}
		return os;
	}
}


