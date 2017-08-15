// SortingApp.cpp: Defines the entry point for the console application.
//

// Local include
#include "stdafx.h"

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
	
	char str[] = "bivbdbdyurewgcafwd"; // Example string
	insertion_sort(str, (int)strlen(str)); // Sorting function application (inserting)
	cout << "Sorting a string by inserting: " << str << endl; // Output
	
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
	
	char str2[] = "vrnairtgunirtnitr"; // Example string
	bubble_sort(str2, (int)strlen(str2)); // Sorting function application (bubble)
	cout << "Sorting a string by bubble method: " << str2 << endl; // Output
		
    getch(); // Gets a character from the console without echo
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

