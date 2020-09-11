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


namespace sdds {
	void gifting(char* description) {

		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> description;
	}

	void gifting(double& price) {

		cout << "Enter gift price: ";
		cin >> price;
		while (price < 0 || price > MAX_PRICE) {
			cout << "Gift price must be between 0 and 999.99" << endl;
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

	void display(const Gift& thing) {
			
			cout << "Gift Details:" << endl;
			cout << "Description: " << thing.g_description << endl;
			cout << "Price: " << thing.g_price << endl;
			cout << "Units: " << thing.g_units << endl;
	 }
	
}