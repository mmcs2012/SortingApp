#pragma once
#include "stdafx.h"
#include "CBook.h"
#include <stdlib.h>

CBook::CBook()
{
}

CBook::CBook(char *pName, char *pAuthor, char *pIsbn)
{
	strcpy(m_acName, pName);
	strcpy(m_acAuthor,pAuthor);
	strcpy(m_acIsbn, pIsbn);
}

CBook::~CBook()
{
}

/*
ostream &operator<<(ostream &stream, CBook &object)
{
	cout << object.m_acName << endl;
	cout << object.m_acAuthor << endl;
	cout << object.m_acIsbn << endl << endl;
	return stream;
} */