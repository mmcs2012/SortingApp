#pragma once
#include <string.h>
#include <iostream>

class CBook
{
private:
	char m_acTitle[40];
	char m_acAuthor[40];
	char m_acIsbn[40];
public:
	CBook();
	CBook(char *pTitle, char *pAuthor, char *pIsbn);
	~CBook();
	int operator<(CBook &ob) { return strcmp(m_acIsbn, ob.m_acIsbn) < 0; } // Inline function, operator overloading
	void print() { std::cout << m_acIsbn << "\t" << m_acTitle << " by " << m_acAuthor << std::endl; } //Inline function
	/* friend ostream &operator<<(ostream &stream, CBook &object); */
};