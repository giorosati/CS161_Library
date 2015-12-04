/*********************************************************************
** Author: Giovanni Rosati
** Date: 2015-12-02
** Description: Function definitions for Library class

*********************************************************************/
//Library.cpp

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
	//add a book to a patrons book vector
	//change the books location, checkedOutBy, and dateCheckedOut parameters

	Book* book = getBook(bID);  //get the book pointer
	Patron* patron = getPatron(pID);  // get the patron pointer

	if (book == NULL) //test if book is in the holdings vector
	{
		return "book not found";
	}

	else if (patron == NULL)  //test if patron is in the members vector
	{
		return "patron not found";
	}
	else
	{
		if (book->getLocation() == CHECKED_OUT) //test if book is already checked out
			return "book already checked out";
		else if (book->getLocation() == ON_HOLD_SHELF) //test if book is on hold
		{
			return "book on hold by another patron";
		}
		else //check out the book
		{
			book->setCheckedOutBy(patron);
			book->setDateCheckedOut(currentDate);
			book->setLocation(CHECKED_OUT);

			//push book pointer into the patrons checked out books vector
			patron->addBook(book); //add to the vector
			if (patron = book->getRequestedBy()) //clear requested by if it was on hold
			{
				book->setRequestedBy(NULL);
			}
		}
	}
	return "check out successful";
};

string Library::returnBook(string bID)
{
	//remove a book from a patrons vector of books
	//update books location (possibly to on hold shelf), checkedOutBy, and dateCheckedOut
	Book* book = getBook(bID);  //get the book pointer
	if (book == NULL) //test if book is in the holdings vector
	{
		return "book not found";
	}
	else if (book->getCheckedOutBy() == NULL) //test if book is not checked out
	{
		return "book already in library";
	}
	//return the book
	//find patron and remove book pointer from checkedoutbooks vector
	Patron *patron = book->getCheckedOutBy();
	patron->removeBook(book);

	if (book->getRequestedBy() != NULL)
		book->setLocation(ON_HOLD_SHELF);
	if (book->getRequestedBy() == NULL)
		book->setLocation(ON_SHELF);
	book->setCheckedOutBy(NULL);
	book->setDateCheckedOut(NULL);
	return "successful";
};

string Library::requestBook(string pID, string bID)
{
	//change requestedBy and location as needed

	Book* book = getBook(bID);  //get the book pointer
	Patron* patron = getPatron(pID);  // get the patron pointer

	if (book == NULL) //test if book is in the holdings vector
		return "book not found";
	if (patron == NULL)  //test if patron is in the members vector
		return "patron not found";
	
	Patron* onHoldTestPatron = book->getRequestedBy(); //get on hold by (patron pointer)
	if (onHoldTestPatron != NULL) //test if book already on hold
		return "book already on hold";
	
	//process request
		book->setRequestedBy(patron); //set requested by
		if (book->getLocation() == ON_SHELF)  //test if book is on the shelf
			book->setLocation(ON_HOLD_SHELF);
	return "request successful";
};

string Library::payFine(string pID, double payment)
{
	//code to modify a patron's fines due amount
	Patron* patron = getPatron(pID);  // get the patron pointer
	if (patron == NULL)  //test if patron is in the members vector
	{
		return "patron not found";
	}
	else
	{
		payment = -1 * payment;
		patron->amendFine(payment);
		return "payment successful";
	}
};

void Library::incrementCurrentDate()
{
	currentDate = currentDate + 1; //adds one to current date each time this function is called

	//iterate through books, add fee to correct patron for each overdue book
	int size = holdings.size();

	//cout << "size of holdings vector is: " << size << endl;

	for (int i = 0; i < size; i++)
	{
		//test each book
		//cout << "book iteration counter is: " << i << endl;

		Book* book = holdings.at(i);
		Patron* checkedOut = book->getCheckedOutBy();

		if (checkedOut != NULL) //test if book is checked out
		{
			int dateOut = book->getDateCheckedOut();
			int length = book->getCheckOutLength();
			int dateDue = dateOut + length;
			if (dateDue < currentDate) //true only if book is past due
			{
				Patron* patron = book->getCheckedOutBy();
				patron->amendFine(0.10);
			}
		}
	}
};

Patron* Library::getPatron(string pID)
{
	Patron* patronPointer = NULL;  //initialize a temp patron pointer to NULL
	int size = members.size();
	for (int i = 0; i < size; i++)  //iterate through each member in the vector
	{
		Patron* testPatronPointer = members.at(i); //get the pointer
		string patronID = testPatronPointer->getIdNum();  //get the patron ID
		if (pID == patronID)  //see if ID's match
		{
			patronPointer = testPatronPointer; //capture the pointer if found
		}
	}
	return patronPointer;  //if the patron is not found, returns a NULL pointer
};

Book* Library::getBook(string bID)
{
	Book* book = NULL;  //initialize a temp book pointer to NULL
	int size = holdings.size();
	for (int i = 0; i < size; i++)  //iterate through each book in the vector
	{
		Book* testBookPointer = holdings.at(i); //get the pointer
		string testBookID = testBookPointer->getIdCode();  //get the book ID
		if (bID == testBookID)  //see if ID's match
		{
			book = testBookPointer; //capture the pointer if found
		}
	}
	return book;  //if the book is not found, returns a NULL pointer
};