#ifndef _BOOK_
#define _BOOK_
#include <iostream>
#include <fstream>
#include <string>
#include "MediaItem.h"
#include "Author.h"
using namespace std;

class Book : public MediaItem {
public:
	Book(string name, int am, string g, Author* a) : MediaItem(name, am, "Book"), genre(g) {
		authorPtr = new Author();  // dynamically allocate memory for author pointer
		*authorPtr = *a;
	}
	Book(string name, int am, string g) : MediaItem(name, am, "Book"), genre(g), authorPtr(new Author()) {}
	Book(string name, int am) : MediaItem(name, am, "Book"), genre("N/A"), authorPtr(new Author()) {}
	Book() : genre("N/A"), authorPtr(new Author()) {}
	Book(Book& source) { *this = source; }
	
	virtual ~Book();

	// setters & getters:
	Author* getAuthor() { return authorPtr; }
	void setAuthor(Author* a) { 
		authorPtr = new Author();
		*authorPtr = *a;
	}
	string getGenre() { return genre; }
	void setGenre(string g) { genre = g; }

	// overriden vitrual functions
	string getDetails() override;
	string getDetailsWithoutAmount() override;
	string getCreatorName() override { return authorPtr->getName(); }

	Book& operator=(Book& source);

	friend ostream& operator<<(ostream& output, Book& d);

private:
	string genre;
	Author* authorPtr;  // pointer to Author object

};

#endif //_BOOK_