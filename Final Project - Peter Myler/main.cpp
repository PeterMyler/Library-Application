#include <iostream>
#include <fstream>
#include "Library.h"
#include "Magazine.h"
#include "Book.h"
#include "Author.h"

using namespace std;

int main()
{
	// create some objects
	Library lib1("TU Dublin Library", 100);
	lib1.readAllData();
	lib1.displayItems();
	
	Author author1("Author 1", "the moon 1");
	Book book1("test book 1", 4, "genre 1", &author1);

	Author author2("Author 2", "the moon 2");
	Book book2("test book 2", 1, "genre 2", &author2);

	//Magazine mag1("idk", 15, "company", 25);

	// exceptions:
	// trying to add item when library is full
	lib1.addItem(&book1);
	// tring to remove non-existant item from the library
	lib1.removeItem(&book1);


	// copying:
	// creating new object by copying another object
	Book book3(book2);
	cout << book3 << endl;

	// copying object with overloaded =
	book2 = book1;
	cout << book2 << endl;

	cout << book3 << endl;


	// file handling:
	// read in the stored MediaItems.txt data into the library class vector
	//lib1.readAllData();

	// add/remove item
	//lib1.addItem(&book1);
	//lib1.removeItem(&book1);

	// write data from the library class vector to MediaItems.txt
	lib1.writeAllData();
	lib1.displayItems();


	lib1.sortItemsByAuthor();
	lib1.displayItems();
	lib1.displayItemsWithName("gOlDeN sOn");
	lib1.displayItemsWithAuthor("pIeRcE BrOwN");

	return 0;
}

