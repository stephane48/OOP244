#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 6
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
/*I have done all the coding by myself and only copied the code that my professor
provided to complete this program.*/

#ifndef SDDS_PARKING_H__

#define SDDS_PARKING_H__



#include "Menu.h"

#include "Car.h"

#include "Motorcycle.h"



const int MAXSPOTS = 100;



namespace sdds {

	class Parking : public Menu {

	private:

		char* fileName;

		Menu parkingMenu;

		Menu vehicleMenu;

		int numOfSpots;

		Vehicle* spots[MAXSPOTS];

		int numOfParkedVeh;



		void setEmpty();

		bool isEmpty() const; // check if it is empty or not.

		void parkingStatus() const; //  function does not receive or return anything and only prints a message

		void parkVehicle(); // the function for the Vehicle object to display, get user input and do accordingly

		void returnVehicle(); // the function for " Returning the Vehicle "

		void vehicleList() const; // the function prints the " parked vehicles"

		bool parkingClose(); // the function to close the parking 

		bool exitApp() const; // the function to exit the app

		bool loadFile(); // the function checks if the park value is loaded or not

		void saveFile() const; // the function check if the function is empty or not 

	public:

		using Menu::Menu;

		Parking();

		Parking(const char* datafile, int noOfSpots);

		Parking(const Parking& pCopy) = delete;

		Parking& operator=(const Parking& pCopy) = delete;

		void setFileName(const char* fName);

		int run();

		~Parking();

	};

}

#endif