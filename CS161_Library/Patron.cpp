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
	checkedOutBooks = vector<Book*>();
	fineAmount = 0;
};

//deconstructor
//Patron::~Patron()
//{
//	//cout <<"Deconstructor has run" endl;
//};

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
	//add book pointer to the vector
	checkedOutBooks.push_back(b);
};

void Patron::removeBook(Book* b)
{
	//step 1 - find position of the book in the vector
	int position = NULL;
	for (int i = 0; i < checkedOutBooks.size(); i++)
	{
		if (b = checkedOutBooks.at(i))
		{
			int position = i;
		}
	}
	if (position == NULL)  //case where book is not in the vector
	{
		cout << "Book not checked out to this Patron." << endl;
	}
	else  //remove the book pointer from the vector
	{
		checkedOutBooks.erase(checkedOutBooks.begin() + position);
	}
};

double Patron::getFineAmount()
{
	return fineAmount;
};

void Patron::amendFine(double amount)
{
	//code to increase or decrease fineAmount
	{
		fineAmount = fineAmount + amount;
	}
};