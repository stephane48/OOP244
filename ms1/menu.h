/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/



#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
using namespace std;

namespace sdds
{
	class Menu;
	class MenuItem
	{
		friend Menu;
	private:
		char* nameTitle;
		MenuItem(); // No argument constructor
		MenuItem(const char*); // one argument constructor
		ostream& display(std::ostream&) const; //  ostream to display the contents
		~MenuItem(); // default destuctor
	};

	class Menu
	{
		const int MAX_NO_OF_ITEMS = 10;
		char* title;
		MenuItem* menuItem;
		int idt;
		int noItem;
	public:
		Menu(); // No argument constructor
		Menu(const char*, int indent = 0); // two argument constructor
		Menu(const Menu&); // copy constructor that takes the class instance
		Menu& operator=(const Menu&); // the operator overload to assign (copy assignment)
		~Menu(); // default destuctor
		void setTitle(const char*); // the function to set the title
		void setItems(const MenuItem*, int); // the function to set the item name
		void add_arguments(const char*, const MenuItem*, int, int); // a function that takes 4 arguments to copy the class instance
		operator bool() const; // cast overload
		operator int() const;
		bool isEmpty() const; // function to check if the object is empty or not
		void display() const; // the display function
		void add(const char*); 	// add function to add a new menuItem
		int run() const; // run function 
		Menu& operator=(const char*); // operator overload to set new title
		Menu& operator<<(const char*);	// operator overload to add new elements
	};
	void indent(std::ostream&, int); // this function indents the menu 
}

#endif // !SDDS_MENU_H
