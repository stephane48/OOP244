#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 06_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
#pragma once
#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include<iostream>


namespace sdds {
    class Basket {
		char* m_fruitName;
		int m_qty;
		double m_price;
	public:
		Basket();
		Basket(const char*, int, double);
		Basket(const Basket& basket2);
		~Basket();

		void setName(const char*);
		void setQty(int);
		void setPrice(double);
		bool isempty() const;
		bool addPrice(double);
		Basket& operator=(const Basket&);
		bool operator==(const Basket&);
		bool operator!=(const Basket&);
		std::ostream& display(std::ostream& os)const;
	};
		std::ostream& operator<<(std::ostream& os, const Basket& bsk);

}


#endif // !NAMESPACE_TOOLS_H