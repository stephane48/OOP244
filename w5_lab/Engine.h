#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 05_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
#pragma once
#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <string.h>
#include <array>

namespace sdds {
	const int MAX_NAME = 30;

	class Engine {
		char name[MAX_NAME + 1];
		double size;
	public:
		Engine(); // default constructot
		Engine(const char* nameType, double size_engine); // two arguments constructor
		double get() const; // return the size of the engine
		void display() const; // display thge content of the class Engine

	};


}


#endif // !NAMESPACE_TOOLS_H