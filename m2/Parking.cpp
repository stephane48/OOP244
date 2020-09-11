/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"


using namespace std;

namespace sdds {

	
	Parking::Parking(const char* title) {

		if (title == nullptr || strlen(title) == 0) {
			park = nullptr;
		}
		else {
			park = new char[strlen(title) + 1];
			strcpy(park, title);
		}

		if (loadDataFile()) {

			Menu_element.setTitle("Parking Menu, select an action:");
			Menu_element << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
			Vehicle_element.setTitle("Select type of the vehicle:");
			Vehicle_element.setIndent(1);
			Vehicle_element << "Car" << "Motorcycle" << "Cancel";
		}
		else {
			cout << "Error in data file" << endl;
		}
	}

	
	bool Parking::isEmpty() {
		return Menu_element.isEmpty();
	}

	
	void Parking::Parkingstatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
	}

	
	void Parking::VehicleFunction() {
		int choice;
		choice = Vehicle_element.run();
		switch (choice) {
		case 1:
			cout << "Parking Car" << endl;
			break;
		case 2:
			cout << "Parking Motorcycle" << endl;
			break;
		case 3:
			cout << "Cancelled parking" << endl;
			break;
		default:
			cout << "Sorry no such";
		}
	}

	
	void Parking::ReturningVehicle() {
		cout << "Returning Vehicle" << endl;
	}

	
	void Parking::PrintParked() {
		cout << "Listing Parked Vehicles" << endl;
	}

	
	bool Parking::closeParking() {
		cout << "Closing Parking" << endl;
		return true;
	}

	
	bool Parking::exitApp() {

		char letter[10];

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		cin >> letter;
		cin.ignore(2000, '\n');
		while (true) {
			if (!strcmp(letter, "y")) {
				cout << "Exiting program!" << endl << "Saving data into " << park << endl;
				return true;
			}
			else if (!strcmp(letter, "n")) {

				return false;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> letter;
				cin.ignore(2000, '\n');
			}
		}

		return false;
	}

	
	bool Parking::loadDataFile() {
		if (park != nullptr) {
			cout << "loading data from ";
			cout << park << endl;
			return true;
		}
		else {
			return false;
		}
	}

	
	void Parking::saveDataFile() {
		if (!isEmpty()) {
			cout << "Saving data info ";
			cout << park << endl;
		}
	}

	
	int Parking::run() {

		if (!isEmpty()) {

			bool flag = true;
			int choice;
			while (flag) {
				Parkingstatus();
				choice = Menu_element.run();

				switch (choice) {
				case 1:
					
					this->VehicleFunction();
					break;
				case 2:
					this->ReturningVehicle();
					break;
				case 3:
					
					this->PrintParked();
					break;
				case 4:
					
					this->closeParking();
					flag = false;
					break;
				case 5:
					
					bool out;
					out = this->exitApp();
					flag = !out;
					break;
				default:
					cout << "something good";
				}

			}
			return 1;
		}
		return 0;
	}

	
	Parking::~Parking() {
		delete[] park;
		park = nullptr;
	}
}