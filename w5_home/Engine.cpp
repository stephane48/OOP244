/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 05_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Engine.h"
#include "Ship.h"
using namespace std;

namespace sdds {
	double Engine::get() const {
		return this->size;
	}

	void Engine::display() const {
		cout << this->size << " liters - " << this->name << endl;
	}

	Engine::Engine() {
		this->size = 0;
		this->name[0] = '\0';

	}



	Engine::Engine(const char* nameType, double size_engine) {
		if (size_engine > 0 && nameType[0] != '\0')
		{
			strcpy(name, nameType);
			this->size = size_engine;
		}
		else
			Engine();
	}


};