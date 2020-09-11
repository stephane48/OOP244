/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 04_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Saiyan.h"
using namespace std;

namespace sdds {
	Saiyan::Saiyan() {
		m_name[0] = '\0';
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {
		//strncpy(this->m_name, name, MAX_NAME);
		/*m_dob = dob;
		m_power = power;
		m_super = false;*/
		set(name, dob, power);
	}

	bool Saiyan::isSuper() const {
		return m_super;
	}

	bool Saiyan::isValid() const {
		bool valid;
		/*if (m_name == nullptr) {
			valid = false;
		}
		else
		{
			if (strlen(m_name)== 0|| m_name[0] == '\0' || m_dob > 2019 || m_power <= 0) {
				valid = false;
			}
			else {
				valid = true;
			}
		}
		return valid;*/
		if (m_name[0] == '\0') {
			valid = false;
		}
		else
		{
			valid = true;
		}
		return valid;
	}

	void Saiyan::setEmpty() {
		m_name[0] = '\0';
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}

	void Saiyan::display() const {
		if (isValid()) {
			cout << m_name << endl
				<< "DOB: " << m_dob << " Power: " << m_power << endl
				<< "Super Saiyan Ability: ";
			if (m_super) {
				cout << "Super Saiyan." << endl << endl;
			}
			else {
				cout<< "Not super Saiyan." << endl << endl;
			}
		}
		else {
			cout << "Invalid Saiyan!" << endl;
		}
	}

	void Saiyan::set(const char* name, int dob, int power, bool super) {
		if (name == nullptr || strlen(name) < 1 || dob >= 2020 || power <= 0) { 
			m_name[0] = '\0';
			m_dob = 0;
			m_power = 0;
			m_super = false;
		}
		else {
			//strncpy(this->description, cargo_desc, MAX_DESC);
			//this->description[MAX_DESC - 1] = '\0';

			strcpy(this->m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
	}

	bool Saiyan::hasLost(const Saiyan& other) const {
		bool lost = false;
		if(this->isValid() && other.isValid()) {
			if (this->m_power < other.m_power)
				lost = true;
		}
		return lost; 
	}


}