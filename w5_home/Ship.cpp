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

		engine = nullptr;
		nameShip = nullptr;
		engineNumber = 0; //<=10
		
	}

	Ship::Ship(const char* nameType, Engine array[], int engineNum) {
		engine = nullptr;
		nameShip = nullptr;
		if (nameType != nullptr && array != nullptr && engineNum != 0) {

		engine = new Engine[engineNum];
		nameShip = new char[strlen(nameType) + 1];
		strcpy(nameShip, nameType);
		engineNumber = engineNum;
		for (int i = 0; i < engineNum; i++) {
			engine[i] = array[i];
		}
		}

	}
	Ship::~Ship() {
		delete[] engine;
		engine = nullptr;
		delete[] nameShip;
		nameShip = nullptr;
	}


	bool Ship::empty() const {
		bool check;
		if (nameShip == nullptr && engineNumber == 0) {

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
		if (nameShip == nullptr)
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
		

		if (empty()) {
        cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		}
		else {
			Engine* engine_arr = nullptr;
			engine_arr = new Engine[++engineNumber];

			for (int i = 0;i < engineNumber-1;i++) {
				engine_arr[i] = engine[i];
			}
			
			engine_arr[engineNumber - 1] = e;
			delete[] engine;
			engine = nullptr;

			engine = new Engine[engineNumber];

			for (int i = 0; i < engineNumber; i++) {
				engine[i] = engine_arr[i];
			}
			delete[] engine_arr;
			engine_arr = nullptr;
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

