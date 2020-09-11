/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
/*I have done all the coding by myself and only copied the code that my professor
provided to complete this program.*/


#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#include "Utils.h"

const int MAX_NO_OF_ITEMS = 10;

namespace sdds {

	class MenuItem {
		char* Menuitem;

		MenuItem(); // No argument constructor

		MenuItem(const char* item); // one argument constructor

		void setItem(const char* item);

		MenuItem(const MenuItem& itemSrc) = delete;

		MenuItem& operator=(const MenuItem& itemSrc) = delete;

		std::ostream& display() const; //  ostream to display the contents

		~MenuItem(); // default destuctor

		friend class Menu;

	};



	class Menu {

		char* Title;

		MenuItem* MenuItems[MAX_NO_OF_ITEMS];

		int ItemNum;

		int Identation;

	public:

		Menu(); // No argument constructor

		Menu(const char* ttl, int identLev = 0); // two argument constructor

		Menu(const Menu& menuSrc); // copy constructor that takes the class instance

		Menu& operator=(const Menu& menuSrc); // the operator overload to assign (copy assignment)

		void setEmpty();

		void setTitle(const char* ttl); // the function to set the title

		void setItems(MenuItem* const Items[], int num); // the function to set the item name

		void setIdentation(int identLev); // the function set the indentation

		operator bool() const; //cast overload

		bool isEmpty() const; // function to check if the object is empty or not

		std::ostream& display() const; // the display function

		Menu& operator=(const char* ttl); // operator overload to set new title

		void add(const char* newMenuItem); // a function that takes 4 arguments to copy the class instance

		Menu& operator<<(const char* item); // operator overload to add new elements

		int run() const; // the run function

		operator int() const;

		virtual ~Menu();

	};

}

#endif



































