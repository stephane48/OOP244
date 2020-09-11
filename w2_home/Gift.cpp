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
#include "Gift.h"
using namespace std;


namespace sdds
{
	void gifting(char* description) {

		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> description;
	}

	void gifting(double& price) {

		cout << "Enter gift price: ";
		cin >> price;
		while (price < 0 || price > MAX_PRICE) {
			cout << "Gift price must be between 0 and 999.99";
			cout << "Enter gift price: ";
			cin >> price;
		}
	}

	void gifting(int& units) {
		cout << "Enter gift units: ";
		cin >> units;
		while (units < 1) {
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> units;
		}
	}



	bool wrap(Gift& good) {
		if (good.wrap != nullptr) {
			cout << "Gift is already wrapped!" << endl;
			return false;
		}
		else
		{
                        cout << "Wrapping gifts..." << endl;
			cout << "Enter the number of wrapping layers for the Gift: ";
			cin >> good.wrap_layers;
			while (good.wrap_layers < 1) {
				cout << "Layers at minimum must be 1, try again." << endl;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> good.wrap_layers;
			}
			good.wrap = nullptr;
			good.wrap = new Wrapping[good.wrap_layers];

			for (int i = 0; i < good.wrap_layers; i++) {
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> good.wrap[i].patern;
			}
			return true;
		}
	}
	bool unwrap(Gift& bad) {
		if (bad.wrap == nullptr) {
			cout << "Gift isn't wrapped! Can't unwrap." << endl;//n
			return false;
		}
		else {
			cout << "Gift being unwrapped." << endl;
			delete[] bad.wrap;
			bad.wrap_layers = 0;
			bad.wrap = 0;//o
		}
		return true;


	}

	void gifting(Gift& bien) {
		cout << "Preparing a gift..." << endl;
		gifting(bien.g_description);
		gifting(bien.g_price);
		gifting(bien.g_units);
		
		wrap(bien);

	}

	void display(const Gift& mal) {
		if (mal.wrap == nullptr)
		{
			cout << "Gift Details:" << endl;
			cout << "Description: " << (mal.g_description) << endl;
			cout << "Price: " << mal.g_price << endl;
			cout << "Units: " << mal.g_units << endl;
			cout << "Unwrapped" << endl;
		}
		else
		{
			cout << "Gift Details:" << endl;
			cout << "Description: " << (mal.g_description) << endl;
			cout << "Price: " << mal.g_price << endl;
			cout << "Units: " << mal.g_units << endl;
			cout << "Wrap Layers: " << mal.wrap_layers << endl;
			for (int j = 0; j < mal.wrap_layers; j++) {
				cout << "Wrap #" << j + 1 << ": " << mal.wrap[j].patern << endl;
			}
		}
	}
}