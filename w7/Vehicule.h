#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: w7
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/


#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sdds {
	 const int MIN_SPEED = 100;
	 const int MAX_SPEED = 140;


	class Vehicle {
		int m_speed;
		int m_noOfSeats;
	public:
		Vehicle();
		Vehicle(int speed, int seat);
		bool finetune();
		ostream& display(ostream& os) const;
		istream& input(istream& in);
		
	};

	ostream& operator<<(ostream& os, const Vehicle& v);
	istream& operator>>(istream& in, Vehicle& V);
	
}

#endif

