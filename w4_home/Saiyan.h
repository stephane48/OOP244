/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 04_home
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/


#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

namespace sdds {

	const int MAX_NAME = 30;

	class Saiyan {
		char* m_name;
		int m_dob;
		int m_power;
		bool m_super;
		int m_level = 0;

	public:

		Saiyan();// this is the constructor and we  are setting it to empty state

		Saiyan(const char* name, int dob, int power); // we are setting the constructor to 03 arguments
			

		~Saiyan();

		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool hasLost(Saiyan& other);
		void powerup();
	};

}
#endif // !SDDS_SAIYAN_H
