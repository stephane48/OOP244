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
#include "Vehicle.h"

using namespace sdds;
using namespace std;
namespace sdds {
	Vehicle::Vehicle(){
		m_speed = 0;
		m_noOfSeats = 0;
	}

	Vehicle::Vehicle(int speed, int seat) {
		if (speed >= MIN_SPEED && seat > 0) {
			m_speed = speed;
			m_noOfSeats = seat;
		}
		else {
			*this = Vehicle();
		}

	}
	/*Vehicle::~Vehicle() {
		delete[] m_fruitName;
		m_fruitName = nullptr;
	}*/
	bool Vehicle::finetune() {
		bool fine;
		if (m_speed > MAX_SPEED) {
			m_speed = MIN_SPEED;
			fine = true;
		}
		else {
			cout << "The car cannot be tuned" << endl;
			fine = false;
		}
		return fine;
	}

	ostream& Vehicle::display(ostream& os) const {
		if (m_speed == 0 && m_noOfSeats == 0) {
			os << "This Car is not initiated" << endl;
		}
		else if (m_speed >= MIN_SPEED && m_noOfSeats > 0) {
			os << "|" << m_speed << "|" << m_noOfSeats << endl;
		}
		if (m_speed > MAX_SPEED) {
			os << "Car has to be fine tuned for speed limit" << endl;
		}
		return os;
	}

	istream& Vehicle::input(istream& in) {
		int sd;
		cout << "Enter the Vehicle`s speed: ";
		in >> sd;
		int st;
		cout << "Enter no of seats: ";
		in >> st;

		if (sd >= MIN_SPEED && st > 0) {
			m_speed = sd;
			m_noOfSeats = st;
		}
		else {
			*this = Vehicle();
		}
		return in;
	}

	ostream& operator<<(ostream& os, const Vehicle& v) {
		v.display(os);
		return os;
	}
	
	istream& operator>>(istream& in, Vehicle& V) {
		V.input(in);
		return in;
	}
}


