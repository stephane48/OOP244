/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 5
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
/*I have done all the coding by myself and only copied the code that my professor
provided to complete this program.*/
#include <iostream>

#include "Car.h"



namespace sdds {

	Car::Car() {

		Vehicle::setEmpty();

		carWash = false;

	}



	Car::Car(const char* plate, const char* makeModel, int spotNum, bool flag) : Vehicle(plate, makeModel, spotNum) {

		carWash = flag;

	}



	std::istream& Car::read(std::istream& istr) {

		if (isCsv()) {

			Vehicle::read(istr);

			int option;

			istr >> option;

			carWash = option;

			istr.ignore();

		}

		else {

			std::cout << "\nCar information entry" << std::endl;

			Vehicle::read(istr);

			std::cout << "Carwash while parked? (Y)es/(N)o: ";

			carWash = yes();

		}



		return istr;

	}



	std::ostream& Car::write(std::ostream& ostr) const {

		if (isEmpty()) {

			ostr << "Invalid Car Object" << std::endl;

		}

		else {

			if (isCsv()) {

				ostr << "C,";

				Vehicle::write(ostr);

				ostr << int(carWash) << std::endl;

			}

			else {

				ostr << "Vehicle type: Car" << std::endl;

				Vehicle::write(ostr);

				if (carWash) {

					ostr << "With Carwash" << std::endl;

				}

				else {

					ostr << "Without Carwash" << std::endl;

				}

			}

		}



		return ostr;

	}



	Car::~Car() {



	}

}


