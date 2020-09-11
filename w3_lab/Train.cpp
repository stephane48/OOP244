/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 02_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Train.h"
using namespace std;


namespace sdds {
	void Train::setTrain(const char* nom, int idTrain) {
		if (nom == nullptr || nom[0] == '\0' || idTrain < 1)
		{
				name[0] = '\0';
				id = 0;
		}else{
			strncpy(name , nom, MAX_NAME);
			id = idTrain;
		}
		cargo = nullptr;
	}

	bool Train::isEmpty() const {
		if ( id < 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if ((name[0] == '\0' || id < 0 )) {
			cout << "This is an empty train." << endl;
		}
		else
		{
			cout << "Name: " << name << " ID: " << id << endl;

			if (cargo != nullptr) {
				cout << "Cargo: " << cargo->description << " Weight: " << cargo->weight << endl;
			}
			else
			{
				cout << "No cargo on this train." << endl;
			}
		}

	}

	void Train::loadCargo(Cargo cargoTrain) {
         cargo = new Cargo;
		*cargo = cargoTrain;
	}

	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}
}