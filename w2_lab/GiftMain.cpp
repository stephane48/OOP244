/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory & Function Overloading
// File GiftMain.cpp
// Version 1.0
// Date 2020/01/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
// Revision History
// -----------------------------------------------------------
// Name Date Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Gift.h"
#include "Gift.h" 
using namespace std;
using namespace sdds;
int main() {
	
	int numberOfGifts = 0;
	
	
	Gift* pgift = nullptr; //define the pointer and set it to null
	
	cout << "Enter number of Gifts to allocate: ";
	cin >> numberOfGifts;
	if (numberOfGifts < 1) return 1;
	
	pgift = new Gift[numberOfGifts]; //allocate dynamic memory
	
	for (int i = 0; i < numberOfGifts; ++i) {
		cout << "Gift #" << i + 1 << ": " << endl;
		
		gifting(pgift[i].g_description); //call the function to enter the first description gift inside the dynamic memory
		
		cin.ignore(2000, '\n'); // clear input buffer
		
		gifting(pgift[i].g_price); // call the function to enter the first price gift inside the dynamic memory
		
		cin.ignore(2000, '\n'); // clear input buffer
		
		gifting(pgift[i].g_units); //call the function to enter the first units gift inside the dynamic memory
		
		cin.ignore(2000, '\n');
		cout << endl;
	}
	
	for (int j = 0; j < numberOfGifts; j++) {
		cout << "Gift #" << j+1<< ": " << endl;
		display(pgift[j]); // call the display function to display each element at the index j
		cout << endl;
	}
		
	  delete [] pgift; // deallocate the dynamic memory
		  
		return 0;
}