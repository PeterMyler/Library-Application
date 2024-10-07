#ifndef _MEDIAITEM_
#define _MEDIAITEM_
#include <iostream>
#include <string>
using namespace std;

class MediaItem {
public:
	MediaItem(string n, int am, string t) : itemName(n), amount(am), itemType(t) {}
	MediaItem() : itemName("N/A"), itemType("N/A"), amount(0) {}
	virtual ~MediaItem();

	// setters & getters:
	void setName(string n) { itemName = n; }
	string getName() { return itemName; }
	void setType(string t) { itemType = t; }
	string getType() { return itemType; }
	int getAmount() { return amount; }
	void setAmount(int am) { amount = am; }
	void incAmount(int am = 1) { amount += am; }
	void decAmount(int am = 1) {
		if (amount > 0)
			amount -= am;
		else
			throw exception("Amount of MediaItem cannot go below 0.");
	}

	// pure virtual functions
	virtual string getDetails() = 0;  
	virtual string getDetailsWithoutAmount() = 0;
	virtual string getCreatorName() = 0;

	// overloading non-member functions
	friend bool operator<(MediaItem&, MediaItem&);   // compare getName()
	friend bool operator==(MediaItem&, MediaItem&);  // compare getDetailsWithoutAmount()
	friend bool operator!=(MediaItem&, MediaItem&);  // not ==

	friend ostream& operator<<(ostream&, MediaItem&);
	friend istream& operator>>(istream&, MediaItem&);

private:
	string itemName;
	int amount;  // amount of copies of the item
	string itemType;

};

#endif //_MEDIAITEM_