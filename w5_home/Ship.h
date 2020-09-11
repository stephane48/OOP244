#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 05_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
#pragma once
#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include<iostream>
#include "Engine.h"

namespace sdds {


	class Ship {
		char *nameShip;
		Engine *engine;
		double distance;
		int engineNumber;

	public:
		Ship(); // default constructo
		Ship(const char* nameType, Engine array[], int engineNum); // constructor three arguments
		~Ship();
		bool empty() const; // check if the ship is empty and return true
		float calculatePower() const; //return the number of engines time 5
		void display() const; // display the content of Ship if it is not empty; otherwise return ""No available data""
		Ship& operator+=(Engine e);
		friend bool operator==(const Ship&, const Ship&);// a friend function that return true if Ships have exactly the same power
	};
	bool operator<(const Ship&, double); // compare the left oerand withnthe right operand

}


#endif // !NAMESPACE_TOOLS_H