#include "Author.h"

Author::~Author() {
	//dtor
}

void Author::displayDetails() {
	cout << "\nAuthor details:\n";
	cout << "Name: " << name << "\n";
	cout << "Country: " << country << "\n\n";
}

ostream& operator<<(ostream& ostr, const Author& d) {
	ostr << "\nAuthor details:\n";
	ostr << "Name: " << d.name << "\n";
	ostr << "Country: " << d.country << "\n\n";
	return ostr;
}