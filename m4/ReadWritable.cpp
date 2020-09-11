/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 3
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ReadWritable.h"

namespace sdds {
	ReadWritable::ReadWritable() {
		flag = false;
	}

	void ReadWritable::setCsv(bool value){
		flag = value;
		}

	bool ReadWritable::isCsv()const {
		return flag;
	}

	ostream& operator<<(ostream& os, const ReadWritable& rw) {
		rw.write(os);
		return os;
	}

	istream& operator>>(istream& is, ReadWritable& rw) {
		rw.read(is);
		return is;
	}
}