/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 3
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
/*I have done all the coding by myself and only copied the code that my professor
provided to complete this program.*/

#include <iostream>

#include "ReadWritable.h"



namespace sdds {

	ReadWritable::ReadWritable() {

		commaSepFlag = false;

	}



	bool ReadWritable::isCsv()const {

		return commaSepFlag;

	}



	void ReadWritable::setCsv(bool value) {

		commaSepFlag = value;

	}



	ReadWritable::~ReadWritable() {



	}



	std::ostream& operator<<(std::ostream& os, const ReadWritable& RW) {

		RW.write(os);

		return os;

	}



	std::istream& operator>>(std::istream& is, ReadWritable& RW) {

		RW.read(is);

		return is;

	}

}