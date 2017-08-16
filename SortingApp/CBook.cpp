#pragma once
#include "stdafx.h"
#include "CBook.h"
#include <stdlib.h>

CBook::CBook() // CBook default constructor
{
}

CBook::CBook(char *pTitle, char *pAuthor, char *pIsbn) // CBook constructor with args
{
	strcpy(m_acTitle, pTitle);
	strcpy(m_acAuthor,pAuthor);
	strcpy(m_acIsbn, pIsbn);
}

CBook::~CBook() // CBook destructor
{
}

/*
ostream &operator<<(ostream &stream, CBook &object)
{
	cout << object.m_acTitle << endl;
	cout << object.m_acAuthor << endl;
	cout << object.m_acIsbn << endl << endl;
	return stream;
} */