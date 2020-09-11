/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 03_home
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {

	const int MAX_NAME = 30; 
	const int MAX_DESC = 20;
	const double MAX_WEIGHT = 700.555;
	const double MIN_WEIGHT = 40.444;

	class Cargo {
		char description[MAX_DESC + 1];
		double weight;

	public:
		const char* takeDesc() const;
		double takeWeight() const;
		void fixeDesc(const char* desc);
		void fixeWeight(double weight);
		void init(const char* cargo_desc, double cargo_weight);
	};

	class Train {
		char name[MAX_NAME + 1]; 
		int id; 
		Cargo* cargo;

	public:
		void setTrain(const char* nom, int idTrain);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo cargoTrain);
		void unloadCargo();
		bool swapCargo(Train& swapCargo);
		bool increaseCargo(double increase);
		bool decreaseCargo(double decrease);
	};

}

#endif