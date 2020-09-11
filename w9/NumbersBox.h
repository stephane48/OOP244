#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: w9
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/


#ifndef W9_NUMBERSBOX_H
#define W9_NUMBERSBOX_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

namespace sdds {

	template<class T>
	class NumbersBox {
	private:

		char name[16];
		int size;
		T* items;
	public:
		NumbersBox() {
			name[0] = '\0';
			size = 0;
			/*for (int i = 0; i < size; i++) {
				items[i] = 0;
			}*/
			items = nullptr;
		}

		NumbersBox(int sizeBox, const char* nameBox) {
			if (sizeBox > 0 && nameBox[0] != '\0') {
				strcpy(name, nameBox);
				size = sizeBox;
				items = new T[size];
			}
			else {
				*this = NumbersBox();
			}

		}

		~NumbersBox() {
			delete[] items;
			items = nullptr;
		}

		T& operator[](int i) {
			return items[i];
		}

		NumbersBox<T>& operator*=(const NumbersBox<T>& other) {
			if (this->size == other.size) {
				for (int i = 0; i < other.size; i++) {
					this->items[i] = this->items[i] * other.items[i];
				}
			}
			return *this;
		}

		NumbersBox<T>& operator+=(T num) {
			/*this->items[size++] = num;*/

			T* source = nullptr;
			source = new T[size + 1];

			for (int i = 0; i < size; i++) {
				source[i] = items[i];
			}
			source[size] = num;
			delete[] items;
			

			size = size + 1;

			items = source;
			return *this;
		}


		ostream& display(ostream& os) const {
			if (size == 0 && name[0] == '\0'&& items == nullptr) {
				os << "Empty Box" << endl;
			}
			else {
					os << "Box name: " << name << endl;
				for (int i = 0; i < size; i++) {
					os << this->items[i];
					if(i < size - 1){
					os << ", ";
					}
				}
				os << endl;
			}
			return os;
		}


	};
	template<typename T>
	ostream& operator<<(ostream& os, NumbersBox<T>& box) {		box.display(os);		return os;	}}

#endif