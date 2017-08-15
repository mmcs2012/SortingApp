#include "stdafx.h"
#include "Book.h"
#include <stdlib.h>

Book::Book()
{
}

Book::Book(char *name, char *author, char *isbn)
{
	strcpy(m_ChrName, name);
	strcpy(m_ChrAuthor, author);
	strcpy(m_ChrIsbn, isbn);
}

Book::~Book()
{
}

/*
ostream &operator<<(ostream &stream, Book &object)
{
	cout << object.m_ChrName << endl;
	cout << object.m_ChrAuthor << endl;
	cout << object.m_ChrIsbn << endl << endl;
	return stream;
} */