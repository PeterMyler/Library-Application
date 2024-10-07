#include "MediaItem.h"

MediaItem::~MediaItem() {
	// dtor
}

bool operator<(MediaItem& i1, MediaItem& i2) {
	return (i1.getName() < i2.getName());
}

bool operator==(MediaItem& i1, MediaItem& i2) {
	return (i1.getDetailsWithoutAmount() == i2.getDetailsWithoutAmount());
}

bool operator!=(MediaItem& i1, MediaItem& i2) {
	return not(i1 == i2);
}

string MediaItem::getDetails() {
	return ("Type: " + itemType + "\nName: " + itemName + "\nAmount: " + to_string(amount) + "\n");
}

string MediaItem::getDetailsWithoutAmount() {
	return ("Type: " + itemType + "\nName: " + itemName + "\n");
}

ostream& operator<<(ostream& ostr, MediaItem& d) {
	ostr << d.getDetails();
	return ostr;
}

istream& operator>>(istream& istr, MediaItem& d) {
	cout << "Enter the name of the item: ";
	istr >> d.itemName;
	cout << "Enter the amount of the item: ";
	istr >> d.amount;
	cout << "Enter the type of the item (\"Book\" / \"Magazine\"): ";
	istr >> d.itemType;
	return istr;
}
