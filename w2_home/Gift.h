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
#include <cctype>
#include <cstring>

namespace sdds
{
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;
	const int MAX_LENGTH = 20;

	struct Gift
	{
		char g_description[MAX_DESC] = "\0";
		double g_price;
		int g_units;
		struct Wrapping* wrap;
		int wrap_layers;
	};
	void gifting(char*);
	void gifting(double&);
	void gifting(int&);
	void gifting(Gift&);
	void display(const Gift&);
	bool wrap(Gift&);
	bool unwrap(Gift&);

	struct Wrapping
	{
		char patern[MAX_LENGTH];
	};

}
#endif // !NAMESPACE_TOOLS_H