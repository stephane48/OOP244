/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 4
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
#ifndef SDDS_Vehicle_H__
#define SDDS_Vehicle_H__
#include "ReadWritable.h"
#include <iostream>
using namespace std;
namespace sdds
{
	class Vehicle : public ReadWritable
	{
		char licencePlate[9];
		char* model;
		int parkNum;
	protected:
		void setEmpty(); //sets the vehicle to an invalid empty state.

		bool isEmpty() const; //check if the vehicle is in an invalid empty sate.

		char* getLicensePlate() const; //returns a read only address of the license plate of the Vehicle.

		char* getMakeModel() const; // returns a read only address of the make and model of the Vehicle.

		void setMakeModel(const char*); // sets model of the vehicle to a new value. 

	public:
		Vehicle();//no argument constructor to check if the vehicle is in empty state

		Vehicle(const char[], const char*, int pkn = 0); //three argument constructor 

		Vehicle(const Vehicle&) = delete;                // those two functions are for 
		Vehicle& operator=(const Vehicle&) = delete;     // memomry leaks in the code  

		virtual ~Vehicle() { //destructor to avoid memory leak and to amke sure model is deallocated. 
			delete[] model;
		}

		int getParkingSpot() const; //returning the int parking spot number

		void setParkingSpot(const int); //setting parking spot number

		bool operator==(const char*) const; //oparotor that compares two licence plate of vehicles

		bool operator==(const Vehicle&) const; //oparotor that compares two vehicles

		ostream& write(ostream&) const; // This function overrides the Read of the ReadWritable class. 

		istream& read(istream&); // this function display vehicle elements.
	};
}


#endif