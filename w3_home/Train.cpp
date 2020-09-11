/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 03_home
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Train.h"
using namespace std;

namespace sdds {

	const char* Cargo::takeDesc() const {
		return description;
	}

	double Cargo::takeWeight() const {
		return weight;
	}

	void Cargo::fixeDesc(const char* desc) {
		strcpy(description, desc);
	}

	void Cargo::fixeWeight(double weight) {
		this->weight = weight;
	}


	void Train::setTrain(const char* nom, int idTrain) {

		if ((nom == nullptr) || (strcmp(nom, "\0") == 0)) {
			strcpy(this->name, "\0");
		}
		else {
			strcpy(this->name, nom);
		}
		if (idTrain < 1) {
			this->id = 0;
		}
		else {
			this->id = idTrain;
		}
			cargo = nullptr;
	}

	bool Train::isEmpty() const {
		bool yesOrNo;
		if ((strcmp(name, "\0") == 0) || (id == 0)) {
			yesOrNo = true;
		}
		else
		{
			yesOrNo = false;
		}
		return yesOrNo;
	}

	void Train::display() const {
		cout << "***Train Summary***" << endl;

		if (isEmpty())
			cout << "This is an empty train." << endl;
		else {
			cout << "Name: " << name << " ID: " << id << endl;

			if (cargo == nullptr)
				cout << "No cargo on this train." << endl;
			else {
				cout << fixed << setprecision(2);
				cout << "Cargo: " << cargo->takeDesc() << " Weight: " << cargo->takeWeight() << endl;
			}
		}
	}

	void Train::loadCargo(Cargo cargoTrain) {
		cargo = new Cargo();
		cargo->fixeDesc(cargoTrain.takeDesc());
		cargo->fixeWeight(cargoTrain.takeWeight());
	}

	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}

	void Cargo::init(const char* cargo_desc, double cargo_weight) {
		/*if (strlen(cargo_desc) <= MAX_DESC + 1) {
			fixeDesc(cargo_desc);
		}
		else {
			fixeDesc("\0");
		}*/
		//if (strlen(cargo_desc) <= MAX_DESC + 1) {
			strncpy(this->description, cargo_desc, MAX_DESC);
			this->description[MAX_DESC - 1] = '\0';
	/*	}
		else
		{
			cargo_desc = "\0";
		}*/
		if (cargo_weight >= MIN_WEIGHT && cargo_weight <= MAX_WEIGHT) {
			//fixeWeight(cargo_weight);
			this->weight= cargo_weight;
		}
		else {
			//fixeWeight(MIN_WEIGHT);
			this->weight = MIN_WEIGHT;
		}	
	}

	bool Train::swapCargo(Train& swapCargo) {
		bool check;
		if (cargo == nullptr || swapCargo.cargo == nullptr)
			check = false;
		else {
			Cargo* temp = cargo;
			cargo = swapCargo.cargo;
			swapCargo.cargo = temp;
			check = true;
		}
		return check;
	}

	bool Train::increaseCargo(double increase) {
		bool change;
		if (cargo == nullptr || cargo->takeWeight() == MAX_WEIGHT)
			change = false;
		else {
			if (cargo->takeWeight() + increase > MAX_WEIGHT) {
				cargo->fixeWeight(MAX_WEIGHT);
				change = true;
			}
			else {
				cargo->fixeWeight(cargo->takeWeight() + increase);

				change = true;
			}
		}
		return change;
	}

	bool Train::decreaseCargo(double decrease) {
		bool expect;
		if (cargo == nullptr || cargo->takeWeight() == MIN_WEIGHT)
			expect = false;
		else {
			if (cargo->takeWeight() - decrease < MIN_WEIGHT)
				cargo->fixeWeight(MIN_WEIGHT);
			else
				cargo->fixeWeight(cargo->takeWeight() - decrease);
			expect = true;
		}
		return expect;
	}
}