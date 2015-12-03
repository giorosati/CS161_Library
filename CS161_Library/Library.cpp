/*********************************************************************
** Author: Giovanni Rosati
** Date: 2015-12-02
** Description: Function definitions for Library class

*********************************************************************/
//LIbrary.cpp

#include "Library.hpp"
#include <iostream>
using namespace std;

//constructor
Library::Library()
{
	holdings = vector<Book*>();
	members = vector<Patron*>();
	int currentDate = NULL;  //should this be initialized to date?
};

void Library::addBook(Book*)
{
	//code to push a book into the vector
};

void Library::addPatron(Patron*)
{
	//code to push a patron into the vector
};

string Library::checkOutBook(string pID, string bID)
{
	//code to add a book to a patrons book vector and change the bnooks location, checkedOutBy, and dateCheckedOut parameters
};

string Library::returnBook(string bID)
{
	//code to remove a book from a patrons vector of books and change the books location (possibly to on hold shelf), checkedOutBy, and dateCheckedOut, and if it was returned late also add fines to the Patron
};

string Library::requestBook(string pID, string bID)
{
	//code to change a books requestedBy parameter and possibly location
};

string Library::payFine(string pID, double payment)
{
	//code to deduct the amount paid from a patron's fines due amount
}

void Library::incrementCurrentDate()
{
	//code to update date if date is not accurate
};

Patron* Library::getPatron(string pID)
{
	//code to return a patron
};

Book* Library::getBook(string bID)
{
	//code to return a book
};