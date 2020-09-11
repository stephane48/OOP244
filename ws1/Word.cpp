/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NHH
 **********************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include "Tools.h"
#include "Word.h"
using namespace std;

namespace sdds
{
	void programTitle() {
		cout <<
			"This program reads a text file from the standard input and analyzes and reports" << endl <<
			"the number of words and their occurrences in the text file." << endl;
	}

	void wordStats(bool logOn) {
		Word words[MAX_NO_OF_WORDS] = { {"",0} };
		char word[MAX_WORD_LEN];
		char lowerCaseWord[MAX_WORD_LEN];
		int NoOfWords = 0;
		int maxLen = 0;
		int foundIndex = 0;
		while (!cin.fail()) {
			cin >> word;
			toLowerCaseAndAlphabeticCopy(lowerCaseWord, word);
			if (lowerCaseWord[0] != 0) {
				if (maxLen < (int)strlen(lowerCaseWord)) {
					maxLen = strlen(lowerCaseWord);
				}
				if (NoOfWords == 0) {
					addWord(words, &NoOfWords, lowerCaseWord);
				}
				else {
					foundIndex = searchWords(words, NoOfWords, lowerCaseWord);
					if (foundIndex < 0) { // word not found in list; so word is new and never read before
						foundIndex = NoOfWords;
						addWord(words, &NoOfWords, lowerCaseWord);
					}
					else {
						words[foundIndex].count++;
					}
				}
				if (logOn) {
					print(&words[foundIndex], false);
					cout << " read so far." << endl;
				}
			}
		}
		cout << "---------------------------------------------------" << endl << "End of data" << endl << "---------------------------------------------------" << endl;
		cout << "Sorting data " << endl;
		sort(words, NoOfWords);
		cout << "Sort ended" << endl;
		report(words, NoOfWords, maxLen);
	}
}