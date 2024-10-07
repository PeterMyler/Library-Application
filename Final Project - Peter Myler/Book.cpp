#include "Book.h"

Book::~Book() {
	if (authorPtr != nullptr)
	{
		delete authorPtr;	  // Release memory allocated for the author object
		authorPtr = nullptr; // Set the pointer to null to avoid double deletion
	}
}

string Book::getDetails() {
	string out = "";
	out += MediaItem::getDetails();  // call parents' method
	out += "Genre: " + getGenre() + "\n";
	out += "Author: " + authorPtr->getName() + "\n";
	out += "Country: " + authorPtr->getCountry() + "\n";
	return out;
}
string Book::getDetailsWithoutAmount() {
	string out = "";
	out += MediaItem::getDetailsWithoutAmount();  // call parents' method
	out += "Genre: " + getGenre() + "\n";
	out += "Author: " + authorPtr->getName() + "\n";
	out += "Country: " + authorPtr->getCountry() + "\n";
	return out;
}

ostream& operator<<(ostream& ostr, Book& d) {
	ostr << d.getDetails();
	return ostr;
}

// overloaded assignment operator for deep coyping of pointer fields
Book& Book::operator=(Book& objBeingCopied)  
{
	// check for self-assignment to avoid copying an object to itself (e.g. book1 = book1)
	if (this == &objBeingCopied)
		return *this;

	// deallocate any memory that the object being updated is holding
	delete authorPtr;

	// shallow copy of the variable values that are not pointers values
	this->setName(objBeingCopied.getName());
	this->setGenre(objBeingCopied.getGenre());
	this->setAmount(objBeingCopied.getAmount());
	this->setType(objBeingCopied.getType());
	
	// deep copy the pointer variable (copy the values the pointer points to and not the pointer value itself)
	if (objBeingCopied.authorPtr)  // check that the pointer for the object being copied has a value
	{
		authorPtr = new Author();  // allocate new memory to hold the author details for the object being updated
		*authorPtr = *objBeingCopied.authorPtr;
	}
	else {
		authorPtr = 0;
	}

	return *this;
}
