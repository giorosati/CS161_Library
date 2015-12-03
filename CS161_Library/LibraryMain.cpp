/*********************************************************************
** Author: Giovanni Rosati
** Date: 2015-12-02
** Description: Main function for testing only

*********************************************************************/
//LibraryMain.cpp

#include "Library.hpp"
#include <iostream>
using namespace std;

int main()
{
	//instructor given code to test some functions

	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");

	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");

	Library lib;

	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.checkOutBook("bcd", "234");

	for (int i = 0; i < 7; i++)
		lib.incrementCurrentDate();

	lib.checkOutBook("bcd", "123");

	lib.checkOutBook("abc", "345");

	for (int i = 0; i < 24; i++)
		lib.incrementCurrentDate();

	lib.payFine("bcd", 0.4);

	double p1Fine = p1.getFineAmount();
	double p2Fine = p2.getFineAmount();

	system("pause");

	return 0;
}