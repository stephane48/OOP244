/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: w7
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <string.h>
#include "Car.h"

using namespace sdds;
using namespace std;
namespace sdds {
	Car::Car() {
		m_carType[0] = '\0';
		m_regYear = 0;
	}

	Car::Car(const char* type, int year, int speed, int seat) : Vehicle(speed , seat) {
		if (type[0] != '\0' && year > MIN_YEAR) {
			strcpy(m_carType, type);
			m_regYear = year;
		}
		else {
			*this = Car();
		}
		Vehicle(speed, seat);

	}
	
	void Car::finetune() {
		if (m_regYear < MIN_YEAR) {
			cout << "Car cannot be tuned and has to be scraped" << endl;
		}
		else {
			Vehicle::finetune();
			cout << "This car is finely tuned to default speed" << endl;
		}
	}

	ostream& Car::display(ostream& os) const {
		if (m_carType[0] == '\0') {
			os << "Car is not initiated yet" << endl;
		}
		else {
			os.setf(ios::left);
			os.width(20);
			os << m_carType;

			os.unsetf(ios::left);
			os.width(0);
			os << m_regYear;
			Vehicle::display(os);
		}
		return os;
	}

	istream& Car::input(istream& in) {
		char name[MAX_CHAR];
		cout << "Enter the car type: ";
		in.getline(name, MAX_CHAR);
		

		int y;
		cout << "Enter the car registration year: ";
		in >> y;
		if (y > MIN_YEAR && name[0] != '\0') {
			m_regYear = y;
			strcpy(m_carType, name);
		}
		else {
			m_regYear = 0;
			
		}
		Vehicle::input(in);
		return in;
	}

	ostream& operator<<(ostream& os, const Car& C) {
		C.display(os);
		return os;
	}

	istream& operator>>(istream& in, Car& C) {
		C.input(in);
		return in;
	}
}


