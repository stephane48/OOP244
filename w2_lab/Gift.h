/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 02_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H
#include<iostream>

namespace sdds {
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;

	struct Gift
	{
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
	};

		void gifting(char*);
		void gifting(double&);
		void gifting(int&);
		void display(const Gift&);


}
#endif // !NAMESPACE_TOOLS_H