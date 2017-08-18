// SortingApp.cpp: Defines the entry point for the console application.
//

// Local include
#include "stdafx.h"
#include "CBook.h"

// Global include
#include <iostream> 
#include <conio.h>
#include <clocale>
#include <ctime>

// Using Standard Library namespace
using namespace std;

// Templates declaration
template <class Stype> void insertionSort(Stype *pItem, int nCount); 
template <class Stype> void bubbleSort(Stype *pItem, int nCount);
template <class Stype> void selectSort(Stype *pItem, int nCount);

void printArray(int *pArr, unsigned int nSize); // Print function declaration

int _tmain(int argc, _TCHAR* argv[]) // Entry point
{
	setlocale(LC_ALL, "Russian"); // Installs the specified system locale
	srand((unsigned int)time(NULL)); // Random number generator initialized by runtime value returned from time()

	const unsigned int nSizeOfArray = 30000; // Size of example array
	unsigned int nStartTime; // Initial running time of the sorting algorithm
	unsigned int nEndTime; // Algorithm work ended
	register unsigned int nReg = 0; // Useful for loops
	
	int anArr[nSizeOfArray]; // Array of int declaration
	while (nReg < nSizeOfArray)
	{
		anArr[nReg] = rand() % 50 - rand() % 50; // Fill the array with random values ​​in the range from -49 to 49 inclusive
		++nReg; // Prefix increment
	}
	cout << "Representation of the generated array (first 50 elements only): ";
	printArray(anArr, 50); // Call print function

	nStartTime = clock();
	selectSort(anArr, nSizeOfArray); // Sorting function application (selection method)
	nEndTime = clock();
	cout << "Sorting an array of integers by the selection method ("
		 << "runtime is " << (nEndTime - nStartTime) / 1000.0 << ")." << endl << "First 50 elements output:" << endl;	
	printArray(anArr, 50);
	
	char acStr[] = "qwertyuiopasdfghjklzxcvbnm"; // Example string
	nStartTime = clock();
	bubbleSort(acStr, (int)strlen(acStr)); // Sorting function application (bubble)
	nEndTime = clock();

	cout << "Sorting a string by bubble method (" << "runtime is " << (nEndTime - nStartTime) / 1000.0 << "):"
		 << endl << acStr << endl << endl; // Output

	
	CBook books[] = { CBook("Thinking in C++", "Bruce Eckel", "1020304050603"),
		CBook("Connexion with Graphs", "Edsger Wybe Dijkstra", "1320305090607"),
		CBook("The C programming language", "Brian Wilson Kernighan", "5794038009455"),
		CBook("The sc unix Time-Sharing System", "Dennis MacAlistair Ritchie", "1120304040609"),
		CBook("What is Object-Oriented Programming?", "Bjarne Stroustrup", "1520304050607"),
		CBook("Accelerated C++", "Andrew Koenig", "1520323050604"),
		CBook("Effective STL", "Scott Meyers", "1520456050607"),
		CBook("C++ Coding Standards", "Herb Sutter", "1545456050600") }; // Array initialization
	unsigned int nSizeOfBooksArray = sizeof(books) / sizeof(*books); // Obtaining size of array

	nStartTime = clock();
	insertionSort(books, nSizeOfBooksArray); // Sorting function application (inserting)
	nEndTime = clock();

	cout << "Sorting a books by inserting (" << "runtime is " << (nEndTime - nStartTime) / 1000.0 << "): " << endl;
	nReg = 0;
	while (nReg < nSizeOfBooksArray) { // Output loop
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

void printArray(int *pArr, unsigned int nSize)
{
	unsigned int nReg = 0;
	while (nReg < nSize) { // Output loop
		cout << pArr[nReg];
		(nReg != nSize - 1) ? (cout << " ") : (cout << endl << endl); // Space attachment
		++nReg; // Prefix increment
	}
}