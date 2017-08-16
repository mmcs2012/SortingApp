// SortingApp.cpp: Defines the entry point for the console application.
//

// Local include
#include "stdafx.h"
#include "CBook.h"

// Global include
#include <iostream> 
#include <conio.h>
#include <clocale>

// Using Standard Library namespace
using namespace std;

// Templates declaration
template <class Stype> void insertionSort(Stype *pItem, int nCount); 
template <class Stype> void bubbleSort(Stype *pItem, int nCount);
template <class Stype> void selectSort(Stype *pItem, int nCount);

int _tmain(int argc, _TCHAR* argv[]) // Entry point
{
	setlocale(LC_ALL, "Russian"); // Installs the specified system locale
	
	int anArr[] = {17,75,375,84,4,46,230}; // Example array of int
	int nSizeOfIntArray = sizeof(anArr) / sizeof(*anArr); // Obtaining size of array
	selectSort(anArr, nSizeOfIntArray); // Sorting function application (selection method)
	cout << "Sorting an array of integers by the selection method: ";
	register int nReg = 0; // Useful for loops
	while (nReg < nSizeOfIntArray) { // Output loop
		cout << anArr[nReg];
		(nReg != nSizeOfIntArray - 1) ? (cout << " ") : (cout << endl << endl); // Space attachment
		++nReg; // Prefix increment
	}
	
	char acStr[] = "qwertyuiopasdfghjklzxcvbnm"; // Example string
	bubbleSort(acStr, (int)strlen(acStr)); // Sorting function application (bubble)
	cout << "Sorting a string by bubble method: " << acStr << endl << endl; // Output

	
	CBook books[] = { CBook("Thinking in C++", "Bruce Eckel", "1020304050603"),
		CBook("Connexion with Graphs", "Edsger Wybe Dijkstra", "1320305090607"),
		CBook("The C programming language", "Brian Wilson Kernighan", "5794038009455"),
		CBook("The sc unix Time-Sharing System", "Dennis MacAlistair Ritchie", "1120304040609"),
		CBook("What is Object-Oriented Programming?", "Bjarne Stroustrup", "1520304050607"),
		CBook("Accelerated C++", "Andrew Koenig", "1520323050604"),
		CBook("Effective STL", "Scott Meyers", "1520456050607"),
		CBook("C++ Coding Standards", "Herb Sutter", "1545456050600") }; // Array initialization
	int nSizeOfBookArray = sizeof(books) / sizeof(*books); // Obtaining size of array
	insertionSort(books, nSizeOfBookArray); // Sorting function application (inserting)
	cout << "Sorting a books by inserting: " << endl;
	nReg = 0;
	while (nReg < nSizeOfBookArray) { // Output loop
		books[nReg].print(); // Class function call
		++nReg;
	}
			
    _getch(); // Gets a character from the console without echo
	return 0; // Successful termination
}

// Template definition of insertion method of sorting
template <class Stype> void insertionSort(Stype *pItem, int nCount) 
{
	register int a, b;
	Stype t;
	for (a = 1; a < nCount; ++a) {
		t = pItem[a];
		for (b = a - 1; b >= 0 && t < pItem[b]; --b)
			pItem[b + 1] = pItem[b];
		pItem[b + 1] = t;
	}
}

// Template definition of bubble method of sorting
template <class Stype> void bubbleSort(Stype *pItem, int nCount)
{
	register int a, b;
	Stype t;
	for (a = 1; a < nCount; ++a) {
		for (b = nCount - 1; b >= a; --b) {
			if (pItem[b - 1] > pItem[b]) {
				t = pItem[b - 1];
				pItem[b - 1] = pItem[b];
				pItem[b] = t;
			}
		}
	}
}

// Template definition of selection method of sorting
template <class Stype> void selectSort(Stype *pItem, int nCount)
{
	register int a, b, c;
	int exchange;
	Stype t;
	for (a = 0; a < nCount - 1; ++a) {
		exchange = 0;
		c = a;
		t = pItem[a];
		for (b = a + 1; b < nCount; ++b) {
			if (pItem[b] < t) {
				c = b;
				t = pItem[b];
				exchange = 1;
			}
		}
		if (exchange) {
			pItem[c] = pItem[a];
			pItem[a] = t;
		}
	}
}

