#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 4
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
/*I have done all the coding by myself and only copied the code that my professor
provided to complete this program.*/

#ifndef SDDS_VEHICLE_H__

#define SDDS_VEHICLE_H__



#include "ReadWritable.h"

#include "Utils.h"



const int MAXLEN = 8;



namespace sdds {

	class Vehicle : public ReadWritable {

		char licensePlate[MAXLEN + 1];

		char* make_model;

		int parkSpotNum;

	protected:

		void setEmpty(); //sets the vehicle to an invalid empty state.

		bool isEmpty() const; //check if the vehicle is in an invalid empty sate.

		const char* getLicensePlate();//returns a read only address of the license plate of the Vehicle.

		const char* getMakeModel(); // returns a read only address of the make and model of the Vehicle.

		void setMakeModel(const char* makeModel); // sets model of the vehicle to a new value. 

	public:

		Vehicle(); //no argument constructor to check if the vehicle is in empty state

		Vehicle(const char* plate, const char* makeModel, int spotNum = 0); //three argument constructor 

		Vehicle(const Vehicle& vCopy) = delete;             // those two functions are for
		Vehicle& operator=(const Vehicle& vCopy) = delete; // memomry leaks in the code  

		int getParkingSpot() const; //returning the int parking spot number

		void setParkingSpot(int spotNum); //setting parking spot number

		friend bool operator==(const Vehicle& v, const char* plate); //oparotor that compares two licence plate of vehicles

		friend bool operator==(const Vehicle& v1, const Vehicle& v2); //oparotor that compares two vehicles

		virtual std::istream& read(std::istream& istr = std::cin); // This function overrides the Read of the ReadWritable class. 

		virtual std::ostream& write(std::ostream& ostr = std::cout) const; // this function display vehicle elements.

		virtual ~Vehicle();

	};



}

#endif //!SDDS_VEHICLE_H__