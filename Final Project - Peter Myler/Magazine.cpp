#include "Magazine.h"

Magazine::~Magazine() {
	//dtor
}

string Magazine::getDetails() {
	string out = "";
	out += MediaItem::getDetails();  // call parents' method
	out += "Company: " + company + "\n";
	out += "Edition: " + to_string(edition) + "\n";
	return out;
}

string Magazine::getDetailsWithoutAmount() {
	string out = "";
	out += MediaItem::getDetailsWithoutAmount();  // call parents' method
	out += "Company: " + company + "\n";
	out += "Edition: " + to_string(edition) + "\n";
	return out;
}

ostream& operator<<(ostream& ostr, Magazine& d) {
	ostr << d.getDetails();
	return ostr;
}
