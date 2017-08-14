// SortingApp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <clocale>

using namespace std;

template <class Stype> void insertion_sort(Stype *item, int count);
template <class Stype> void bubble_sort(Stype *item, int count);
template <class Stype> void select_sort(Stype *item, int count);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	char str[] = "bivbdbdyurewgcafwd";	
	insertion_sort(str, (int)strlen(str));
	cout << "Сортировка строки методом вставки: " << str << endl;
		
	int intgr[7] = {1,7,3,8,4,6,2};
	select_sort(intgr, 7);
	cout << "Сортировка массива целых чисел методом выбора: ";
	register int i;
	for (i = 0; i < 7; ++i) {
		cout << intgr[i];
		if (i != 6) cout << " ";
			else cout << endl;
	}

	char str2[] = "vrnairtgunirtnitr";
	bubble_sort(str2, (int)strlen(str2));
	cout << "Сортировка строки методом пузырька: " << str2 << endl;
		
	_getch();
	return 0;
}

template <class Stype> void insertion_sort(Stype *item, int count)
{
	register int a, b;
	Stype t;
	for (a = 1; a<count; ++a) {
		t = item[a];
		for (b = a - 1; b >= 0 && t < item[b]; --b)
			item[b + 1] = item[b];
		item[b + 1] = t;
	}
}

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

