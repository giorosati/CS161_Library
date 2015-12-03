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
	int currentDate = 0;
};

void Library::addBook(Book* b)
{
	//push a book into the vector
	holdings.push_back(b);
};

void Library::addPatron(Patron* p)
{
	//push a patron into the vector
	members.push_back(p);
};

string Library::checkOutBook(string pID, string bID)
{
	//code to:
	//add a book to a patrons book vector
	//change the books location, checkedOutBy, and dateCheckedOut parameters

	Book* book = getBook(bID);  //get the book pointer
	Patron* patron = getPatron(pID);  // get the patron pointer

	if (book = NULL) //test if book is in the holdings vector
	{
		return "book not found";
	}
	else
	{
		if (patron = NULL)  //test if patron is in the members vector
		{
			return "patron not found";
		}
		else
		{
			Book testBook = *book;  //get book object
			Locale testBookLocation = testBook.getLocation();

			if (testBookLocation == CHECKED_OUT) //test if book is already checked out
				return "book already checked out";
			else if (testBookLocation == ON_HOLD_SHELF) //test if book is on hold
			{
				return "book on hold by another patron";
			}
			else //check out the book
			{
				testBook.setCheckedOutBy(patron);
				testBook.setDateCheckedOut(currentDate);
				testBook.setLocation(CHECKED_OUT);
				if (patron = testBook.getRequestedBy()) //clear requested by if it was on hold
				{
					testBook.setRequestedBy(NULL);
				}
				//push book pointer into the patrons checked out books vector
				Patron tempPatron = *patron; //get the patron object
				tempPatron.addBook(book); //add to the vector
				return "check out successful";
			}
		}
	}
};

string Library::returnBook(string bID)
{
	//code to remove a book from a patrons vector of books and change the books location (possibly to on hold shelf), checkedOutBy, and dateCheckedOut, and if it was returned late also add fines to the Patron
};

string Library::requestBook(string pID, string bID)
{

	//code to:
	//change requestedBy and location as needed

	Book* book = getBook(bID);  //get the book pointer
	Patron* patron = getPatron(pID);  // get the patron pointer

	if (book = NULL) //test if book is in the holdings vector
	{
		return "book not found";
	}
	else
	{
		if (patron = NULL)  //test if patron is in the members vector
		{
			return "patron not found";
		}
		else
		{

		}

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
	Patron* patron = NULL;  //initialize a temp patron pointer to NULL
	for (int i = 0; i < members.size(); i++)  //iterate through each member in the vector
	{
		for (i = 0; i < members.size(); i++)
		{
			Patron* testPatronPointer = members.at(i); //get the pointer
			Patron testPatron = *testPatronPointer;  //get the patron object
			string testPatronID = testPatron.getIdNum();  //get the patron ID
			if (pID == testPatronID)  //see if ID's match
			{
				patron = testPatronPointer; //return the pointer if found
			}
			return patron;  //if the patron is not found, returns a NULL pointer
		}
	}
};

Book* Library::getBook(string bID)
{
	Book* book = NULL;  //initialize a temp book pointer to NULL
	for (int i = 0; i < holdings.size(); i++)  //iterate through each book in the vector
	{
		for (i = 0; i < holdings.size(); i++)
		{
			Book* testBookPointer = holdings.at(i); //get the pointer
			Book testBook = *testBookPointer;  //get the book object
			string testBookID = testBook.getIdCode();  //get the book ID
			if (bID == testBookID)  //see if ID's match
			{
				book = testBookPointer; //return the pointer if found
			}
			return book;  //if the book is not found, returns a NULL pointer
		}
	}
};