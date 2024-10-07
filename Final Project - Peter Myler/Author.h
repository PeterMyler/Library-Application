#ifndef _AUTHOR_
#define _AUTHOR_
#include <iostream>
#include <string>
#include "MediaItem.h"
using namespace std;

class Author {
public:
	Author() : name("N/A"), country("N/A") {}
	Author(string n) : name(n) {}
	Author(string n, string c) : name(n), country(c) {}

	virtual ~Author();

	string getName() { return name; }
	void setName(string n) { name = n; }
	string getCountry() { return country; }
	void setCountry(string c) { country = c; }

	void displayDetails();

	friend ostream& operator<<(ostream& output, const Author& d);

protected:

private:
	string name;
	string country;

};

#endif //_AUTHOR_