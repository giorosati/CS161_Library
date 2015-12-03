/*********************************************************************
** Author: Giovanni Rosati
** Date: 2015-12-02
** Description: Function definitions for Book class

*********************************************************************/
//Book.cpp

#include "Book.hpp"
#include <iostream>
using namespace std;

//default constructor
//Book::Book()
//{
//	idCode = "";
//	title = "";
//	author = "";
//	location = ON_SHELF;
//	checkedOutBy = NULL;
//	requestedBy = NULL;
//	dateCheckedOut = NULL;
//};

//constructor w/parameters
Book::Book(string idc, string t, string a)
{
	idCode = idc;
	title = t;
	author = a;
	location = ON_SHELF;
	checkedOutBy = NULL;
	requestedBy = NULL;
	dateCheckedOut = NULL;
};

//deconstructor
Book::~Book()
{
	//cout <<"Deconstructor has run" endl;
};

int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
};

string Book::getIdCode()
{
	return idCode;
};

string Book::getTitle()
{
	return title;
};

string Book::getAuthor()
{
	return author;
};

Locale Book::getLocation()
{
	return location;
};

void Book::setLocation(Locale l)
{
	location = l;
};

Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
};

void Book::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;
};

Patron* Book::getRequestedBy()
{
	return requestedBy;
};

void Book::setRequestedBy(Patron* p)
{
	requestedBy = p;
};

int Book::getDateCheckedOut()
{
	return dateCheckedOut;
};

void Book::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
};