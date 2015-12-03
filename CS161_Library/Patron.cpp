/*********************************************************************
** Author: Giovanni Rosati
** Date: 2015-12-02
** Description: Function definitions for Patron class

*********************************************************************/
//Patron.cpp

#include "Patron.hpp"
#include <iostream>
using namespace std;

//constructor w/parameters
Patron::Patron(string idn, string n)
{
	idNum = idn;
	name = n;
	checkedOutBooks = vector<Book*>();  //not sure if this is necessary
	fineAmount = 0;
};

//deconstructor
Patron::~Patron()
{
	//cout <<"Deconstructor has run" endl;
};

string Patron::getIdNum()
{
	return idNum;
};

string Patron::getName()
{
	return name;
}

vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
};

void Patron::addBook(Book* b)
{
	//need code here to place the incoming book to the next position of the vector
};

void Patron::removeBook(Book* b)
{
	//code here to remove the book from the vector and possibly rearrange the vector
};

double Patron::getFineAmount()
{
	return fineAmount;
};

void amendFine(double amount)
{
	//code to increase or decrease the fineAmount by the appropriate amount
};