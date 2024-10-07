#ifndef _MAGAZINE_
#define _MAGAZINE_
#include "MediaItem.h"
#include <iostream>
#include <string>
using namespace std;

class Magazine : public MediaItem {
public:
	Magazine(string n, int p, string c, int e) : MediaItem(n, p, "Magazine"), company(c), edition(e) {}
	virtual ~Magazine();

	void setCompany(string c) { company = c; }
	string getCompany() { return company; }
	void setEdition(int e) { edition = e; }
	int getEdition() { return edition; }

	// overriden vitrual functions
	string getDetails() override;  
	string getDetailsWithoutAmount() override;
	string getCreatorName() override { return getCompany(); }

	// overload the << operator
	friend ostream& operator<<(ostream& output, Magazine& d);

private:
	string company;
	int edition;
};

#endif //_MAGAZINE_