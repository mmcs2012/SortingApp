#pragma once
#include <string.h>
#include <iostream>

class Book
{
private:
	char m_ChrName[40];
	char m_ChrAuthor[40];
	char m_ChrIsbn[13];
public:
	Book();
	Book(char *name, char *author, char *isbn);
	~Book();
	int operator<(Book &ob) { return strcmp(m_ChrIsbn, ob.m_ChrIsbn) < 0; }
	void print() { std::cout << m_ChrName << " " << m_ChrAuthor << " " << m_ChrIsbn << std::endl; }
	/* friend ostream &operator<<(ostream &stream, Book &object); */
};