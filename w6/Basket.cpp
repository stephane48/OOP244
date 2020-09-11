/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: 06_in lab
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <string.h>
#include "Basket.h"

using namespace sdds;
using namespace std;
namespace sdds {
	Basket::Basket() {
		m_fruitName = nullptr;
		m_qty = 0;
		m_price = 0;
	}

	Basket::Basket(const char* name, int qty, double price) {
		if (name != nullptr && qty > 0 && price > 0) {
			setName(name);
			setQty(qty);
			setPrice(price);
		}
		else {
			*this = Basket();
		}
			
	}

	Basket::~Basket() {
		delete[] m_fruitName;
		m_fruitName = nullptr;
	}

	Basket::Basket(const Basket& basket2) {
		if (basket2.m_fruitName != nullptr) {
			m_qty = basket2.m_qty;
			m_price = basket2.m_price;
			m_fruitName = new char[strlen(basket2.m_fruitName)+1];
			strcpy(m_fruitName, basket2.m_fruitName);
		}
		else
		{
			Basket();
		}
	}

	void Basket::setName(const char* name) {
		if (name == nullptr) {
			m_fruitName = nullptr;
		}
		else {
			
			m_fruitName = new char[strlen(name) + 1];
			strcpy(m_fruitName, name);
		}
		
	}
	void Basket::setQty(int qty) {
		if (qty < 0) {
			m_qty = 0;
		}
		else {
			m_qty = qty;
		}
		
	}
	void Basket::setPrice(double price) {
		if (price <0) {
			m_price = 0;
		}
		else {
			m_price = price;
		}
		
	}

	bool Basket::isempty() const {
		bool check;
		if (m_fruitName != nullptr || m_qty < 0 || m_price < 0) {
			check = false;
		}
		else {
			check = true;
		}
		return check;
	}

	bool Basket::addPrice(double price2) {
		bool add;
		this->m_price += price2;
		if (m_price > 0) {
			add = true;
		}
		else {
			add = false;
		}
		return add;
	}

	std::ostream& Basket::display(std::ostream& os)const {
		if (this->isempty()) {
			os << "The Basket has not yet been filled" << std::endl;
		}
		else {
			os << "Basket Details" << std::endl;
				os << "Name: " << m_fruitName << std::endl;									
			os << "Quantity: " << m_qty << std::endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Price: " << m_price << std::endl;
			os.unsetf(ios::fixed);
			os.precision(6);
		}
		return os;
	}

	Basket& Basket::operator=(const Basket& basket2) {
		if (this != &basket2) {
			m_qty = basket2.m_qty;
			m_price = basket2.m_price;
			if (basket2.m_fruitName != nullptr) {
				delete[] m_fruitName;
				m_fruitName = new char[strlen(basket2.m_fruitName)+1];
				strcpy(m_fruitName, basket2.m_fruitName);
			}
			else {
				m_fruitName = nullptr;
			}
		}
		return *this;
	}

	bool Basket::operator==(const Basket& basket) {
		bool equal;
		if ((strcmp(this->m_fruitName, basket.m_fruitName) == 0) && this->m_qty == basket.m_qty && this->m_price == basket.m_price) {
			equal = false;
		}
		else {
			equal = true;
		}
		return equal;
	}

	bool Basket::operator!=(const Basket& basket) {
		bool notEqual;
		if ((strcmp(this->m_fruitName, basket.m_fruitName) != 0) && this->m_qty != basket.m_qty && this->m_price != basket.m_price) {
			notEqual = false;
		}
		else {
			notEqual = true;
		}
		return notEqual;
	}
	std::ostream& operator<<(std::ostream& os, const Basket& bsk) {
		bsk.display(os);
		return os;
	}
}


