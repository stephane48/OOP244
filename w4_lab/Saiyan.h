/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 04_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H
#include<iostream>

namespace sdds {
	const int MAX_NAME = 30;
	
	class Saiyan {
		char m_name[MAX_NAME + 1];
		int m_dob;
		int m_power;
		bool m_super;
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		bool isSuper() const;
		bool isValid()const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, bool super = false);
		bool hasLost(const Saiyan& other) const;
	};
}


#endif // !NAMESPACE_TOOLS_H