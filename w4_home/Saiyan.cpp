/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 04_home
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include "Saiyan.h"

using namespace std;

namespace sdds {
	Saiyan::Saiyan() { // this is the constructor and we  are setting it to empty state
		this->setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power) { // we are setting the constructor to 03 arguments
		this->set(name, dob, power);
	}

	Saiyan::~Saiyan() { // deallocate te dynamic memory in the destructor
		delete[] m_name;
		m_name = nullptr;
	}

	bool Saiyan::isSuper() const {
		return m_super;
	}



	bool Saiyan::isValid() const { // this  function check if the object is in a safe empty state, and return true if it's NOT

		if (m_name == nullptr || m_name[0] == '\0' || m_dob > 2020 || m_power < 0) {
			return false;
		}

		else {

			return true;

		}

	}



	void Saiyan::setEmpty() { // set the object ton an empty state
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}



	void Saiyan::display() const { //displays the Saiyan’s name and stats

		if (this->isValid()) {

			cout << m_name << endl;

			cout << "DOB: " << m_dob << " Power: " << m_power << endl;

			cout << "Super Saiyan Ability: ";

			if (m_super == 1) {

				cout << "Super Saiyan." << endl << "Super Saiyan level is: " << m_level << endl;

			}

			else {

				cout << "Not super Saiyan." << endl << endl;

			}

		}

		else {

			cout << "Invalid Saiyan!" << endl;

		}

	}



	void Saiyan::set(const char* name, int dob, int power, int level, bool super) { // this function store valid data in a Saiyan object 
		if (name == nullptr || strlen(name) == 0 || dob > 2020 || power < 0) {
			m_name = nullptr;
			m_dob = 0;
			m_power = 0;
			m_super = super;
			m_level = 0;
		}

		else {
			m_name = new char[strlen(name)+1];
			strcpy(this->m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = level;

		}

	}

	bool Saiyan::hasLost(Saiyan& other) { //receive by reference the oject saiyan oject and increase its poer before returnin won or lost
		if (this->isValid() && other.isValid()) {
			this->powerup();
			other.powerup();

			if (m_power > other.m_power) {
				return false;
			}

			else {
				return true;
			}

		}

		else {

			return false;

		}

	}



	void Saiyan::powerup() { // this function will increase the power of the saiyan object

		if (m_super) {

			m_power *= (m_level + 1);

		}

	}

}
