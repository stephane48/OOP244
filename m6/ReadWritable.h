#pragma once
#pragma once
/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: Milestone 3
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/
/*I have done all the coding by myself and only copied the code that my professor
provided to complete this program.*/

#ifndef SDDS_READWRITABLE_H__

#define SDDS_READWRITABLE_H__

#include <iostream>



namespace sdds {

	class ReadWritable {

		bool commaSepFlag;

	public:

		ReadWritable();

		bool isCsv()const;

		void setCsv(bool value);

		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;

		virtual std::istream& read(std::istream& istr = std::cin) = 0;

		virtual ~ReadWritable();

	};



	std::ostream& operator<<(std::ostream& os, const ReadWritable& RW);

	std::istream& operator>>(std::istream& is, ReadWritable& RW);

}

#endif


