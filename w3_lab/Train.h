/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 03_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H
#include<iostream>

namespace sdds {
	const int MAX_NAME = 30;
	const int MAX_DESC = 20;

	struct Cargo {
		char description[MAX_DESC];
		double weight;
	};

	class Train {
		char name[MAX_NAME +1];
		int id;
		Cargo* cargo;
	public:
		void setTrain(const char*, int);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo);
		void unloadCargo();
	};

}
#endif // !NAMESPACE_TOOLS_H
