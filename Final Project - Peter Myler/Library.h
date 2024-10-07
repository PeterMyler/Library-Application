#ifndef _LIBRARY_
#define _LIBRARY_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "MediaItem.h"
#include "Book.h"
#include "Magazine.h"
using namespace std;

class Library {
public:
	Library(string n, int capacity) : libraryName(n), MAXITEMS(capacity) {}
	Library(string n) : libraryName(n), MAXITEMS(100) {}

	virtual ~Library() {}

	// setters & getters:
	string getName() { return libraryName; }
	void setName(string n) { libraryName = n; }
	string getFilename() { return filename; }
	void setFilename(string f) { filename = f; }
	int getMaxItems() { return MAXITEMS; }

	// <vector> functions
	bool hasItem(MediaItem*);		  // returns true if the vector has the specified item (checks equality)
	void addItem(MediaItem*);		  // add a MediaItem pointer to the vector
	void removeItem(MediaItem*);	  // remove a MediaItem from the vector
	void sortItemsByName();			  // sort the vector of MediaItems by their names
	void sortItemsByAmount();		  // sort the vector of MediaItems by their amount
	void sortItemsByType();			  // sort the vector of MediaItems by their type
	void sortItemsByAuthor();		  // sort the vector of MediaItems by their author/company
	int countItemsInVector();		  // count the number of items (including "amount") in the vector
	MediaItem* findItem(MediaItem*);  // find item in vector (checks equality)

	// display functions
	void displayItems();				  // display the details of each MediaItem in the vector
	void displayItemsWithName(string);	  // display the items that match the given item name
	void displayItemsWithAuthor(string);  // display the items that match the given author/company name

	// file functions
	// (I/O operators for each class have been designed to comply with a specific format, to work with .txt files)
	void readAllData();		// goes through MediaItems.txt, creates all the objects and adds them to the vector
	void writeAllData();	// goes through the vector and writes out all the data to MediaItems.txt

	friend ostream& operator<<(ostream& output, Library& d);

private:
	string libraryName;
	vector<MediaItem*> itemsVector;  // vector of MediaItems
	const int MAXITEMS;	 // maximum allowed number of MediaItems in the vector
	string filename = "MediaItems.txt";
};

#endif //_LIBRARY_