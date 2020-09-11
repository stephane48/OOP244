/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 05_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <string.h>
#include "Ship.h"
using namespace std;

namespace sdds {
	Ship::Ship() {

		engine[0] = Engine();
		nameShip[0] = '\0';
		engineNumber = 0; //<=10
		distance = 0;
	}

	Ship::Ship(const char* nameType, Engine array[], int engineNum) {


		strcpy(nameShip, nameType);

		for (int i = 0; i < 10; i++) {
			engine[i] = array[i];
		}

		engineNumber = engineNum;
		distance = 0;

	}



	bool Ship::empty() const {
		bool check;
		if (nameShip[0] == '\0' && engineNumber == 0) {

			check = true;
		}
		else {

			check = false;
		}

		return check;

	}

	float Ship::calculatePower() const {
		float power = 0;
		int i = 0;
		while (i < engineNumber) {
			power += this->engine[i].get() * 5;
			i++;
		}
		return power;
	}

	void Ship::display() const {
		if (nameShip[0] == '\0')
			cout << "No available data" << endl;

		else {
			cout << this->nameShip << "-";
			cout.setf(ios::fixed);
			cout.width(6);
			cout.precision(2);
			cout << this->calculatePower() << endl;

			for (int i = 0; i < engineNumber; i++)
			{
				this->engine[i].display();

			}

			cout.unsetf(ios::fixed);
			cout.precision(6);
		}

	}

	Ship& Ship::operator+=(Engine e) {

		if (this->nameShip[0] == '\0' || this->engineNumber == 0) {
        cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		}
		else if (engineNumber < 10) {
			engine[engineNumber++] = e;
		}
		return *this;
	}

	bool operator==(const Ship& now, const Ship& after) {
		if (now.calculatePower() == after.calculatePower()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator<(const Ship& actual, double value) {
		if (actual.calculatePower() < value) {
			return true;
		}
		else {
			return false;
		}
	}
}

