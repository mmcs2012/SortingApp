// SortingApp.cpp: Defines the entry point for the console application.
//

// Local include
#include "stdafx.h"
#include "Book.h"

// Global include
#include <iostream> 
#include <conio.h>
#include <clocale>

// Using Standard Library namespace
using namespace std;

// Templates declaration
template <class Stype> void insertion_sort(Stype *item, int count); 
template <class Stype> void bubble_sort(Stype *item, int count);
template <class Stype> void select_sort(Stype *item, int count);

int _tmain(int argc, _TCHAR* argv[]) // Entry point
{
	setlocale(LC_ALL, "Russian"); // Installs the specified system locale
	
	int intgr[] = {1,7,3,8,4,6,2}; // Example array of int
	int intSizeOfIntArray = sizeof(intgr) / sizeof(*intgr); // Obtaining size of array
	select_sort(intgr, intSizeOfIntArray); // Sorting function application (selection method)
	cout << "Sorting an array of integers by the selection method: "; // Output
	register int i = 0;
	while (i < intSizeOfIntArray) {
		cout << intgr[i];
		(i != intSizeOfIntArray-1) ? (cout << " ") : (cout << endl); // Space attachment
		++i; // Increment
	}
	
	char str2[] = "bivbdbdyurewgcafwd"; // Example string
	bubble_sort(str2, (int)strlen(str2)); // Sorting function application (bubble)
	cout << "Sorting a string by bubble method: " << str2 << endl; // Output

	
	Book books[] = { Book("Steel Rat", "Harry Harryson", "1020304050607"),
		Book("Connexion with Graphs", "Edsger Wybe Dijkstra", "1320305090607"),
		Book("The C programming language", "Brian Wilson Kernighan", "5794038009457"),
		Book("The sc unix Time-Sharing System", "Dennis MacAlistair Ritchie", "1120304040607"),
		Book("What is Object-Oriented Programming?", "Bjarne Stroustrup", "1520304050607") };
	int intSizeOfBookArray = sizeof(books) / sizeof(*books);
	insertion_sort(books, intSizeOfBookArray); // Sorting function application (inserting)
	cout << "Sorting a books by inserting: " << endl; // Output
	i = 0;
	// TODO: make printing work properly
	while (i < intSizeOfBookArray) {
		books[i].print();
		++i;
	}
			
    _getch(); // Gets a character from the console without echo
	return 0; // Successful termination
}

// Template definition of insertion method of sorting
template <class Stype> void insertion_sort(Stype *item, int count) 
{
	register int a, b;
	Stype t;
	for (a = 1; a < count; ++a) {
		t = item[a];
		for (b = a - 1; b >= 0 && t < item[b]; --b)
			item[b + 1] = item[b];
		item[b + 1] = t;
	}
}

// Template definition of bubble method of sorting
template <class Stype> void bubble_sort(Stype *item, int count)
{
	register int a, b;
	Stype t;
	for (a = 1; a < count; ++a) {
		for (b = count - 1; b >= a; --b) {
			if (item[b - 1] > item[b]) {
				t = item[b - 1];
				item[b - 1] = item[b];
				item[b] = t;
			}
		}
	}
}

// Template definition of selection method of sorting
template <class Stype> void select_sort(Stype *item, int count)
{
	register int a, b, c;
	int exchange;
	Stype t;
	for (a = 0; a < count - 1; ++a) {
		exchange = 0;
		c = a;
		t = item[a];
		for (b = a + 1; b < count; ++b) {
			if (item[b] < t) {
				c = b;
				t = item[b];
				exchange = 1;
			}
		}
		if (exchange) {
			item[c] = item[a];
			item[a] = t;
		}
	}
}

