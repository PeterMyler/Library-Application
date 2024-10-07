#include "Library.h"

string lowerString(string givenStr) {
	// lowers all the characters in a string and returns it
	string out = "";

	for (char c : givenStr)
		out += tolower(c);

	return out;
}

// ================ Vector Functions ================

bool Library::hasItem(MediaItem* item) {
	// compare each item in the vector to the item provided
	for (MediaItem* mi : itemsVector) {
		if (*mi == *item)
			return true;
	}
	return false;

	//return (find(itemsVector.begin(), itemsVector.end(), item) != itemsVector.end());
}

void Library::addItem(MediaItem* item) {
	try {
		if (countItemsInVector() < MAXITEMS) {
			if (hasItem(item)) {
				// find and increment amount of that item by 1
				// (works even if the item is a copy)
				findItem(item)->incAmount(item->getAmount());
			}
			else {
				// just add the item to the vector
				itemsVector.push_back(item);
			}
		}
		else {  // throwing an exception
			throw out_of_range("Error: Library full. Cannot add item.");
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

void Library::removeItem(MediaItem* item) {
	try {
		if (hasItem(item)) {
			int leftOver = findItem(item)->getAmount() - (item->getAmount());

			if (leftOver == 0)
				itemsVector.erase(remove(itemsVector.begin(), itemsVector.end(), findItem(item)), itemsVector.end());
			else if (leftOver > 0)
				findItem(item)->setAmount(leftOver);
			else
				throw exception("Error: removing more of an item than there exists.");
		}
		else  // throwing an exception
			throw exception("Error: Item cannot be removed because it was not found.\n");
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

int Library::countItemsInVector() {
	int tempCount = 0;

	for (MediaItem* mi : itemsVector) 
		tempCount += mi->getAmount();
	
	return tempCount;
}

MediaItem* Library::findItem(MediaItem* item) {
	try {
		MediaItem* originalItemPtr = nullptr;

		for (MediaItem* mi : itemsVector) {
			if (*mi == *item) {
				originalItemPtr = mi;
			}
		}

		if (originalItemPtr == nullptr)
			throw exception("Cannot find item in the vector.");
		else
			return originalItemPtr;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		exit(1);
	}
}

// ================ Sorting Functions ================

bool compareByName(MediaItem* i1, MediaItem* i2) {
	return (i1->getName() < i2->getName());
}

bool compareByAmount(MediaItem* i1, MediaItem* i2) {
	return (i1->getAmount() < i2->getAmount());
}

bool compareByType(MediaItem* i1, MediaItem* i2) {
	// compares two items by type first, then name
	if (i1->getType() == i2->getType())
		return (compareByName(i1, i2));
	else
		return (i1->getType() < i2->getType());
}

bool compareByAuthor(MediaItem* i1, MediaItem* i2) {
	// compares two items by author/company name first, then item name
	if (i1->getCreatorName() == i2->getCreatorName())
		return (compareByName(i1, i2));
	else
		return (i1->getCreatorName() < i2->getCreatorName());
}

void Library::sortItemsByName() {
	sort(itemsVector.begin(), itemsVector.end(), compareByName);
}

void Library::sortItemsByAmount() {
	sort(itemsVector.begin(), itemsVector.end(), compareByAmount);
}

void Library::sortItemsByType() {
	sort(itemsVector.begin(), itemsVector.end(), compareByType);
}
void Library::sortItemsByAuthor() {
	sort(itemsVector.begin(), itemsVector.end(), compareByAuthor);
}

// ================ File-handling Functions ================

Book* createBookObject(vector<string> data) {
	// each item in the string will corrispond to a specific variable
	if (data.size() != 5)
		throw exception("Data vector for Book item is not the correct length.");

	return new Book(data[0], stoi(data[1]), data[2], new Author(data[3], data[4]));
}

Magazine* createMagazineObject(vector<string> data) {
	// each item in the string will corrispond to a specific variable
	if (data.size() != 4)
		throw exception("Data vector for Magazine item is not the correct length.");
	return new Magazine(data[0], stoi(data[1]), data[2], stoi(data[3]));
}


void Library::readAllData() {
	// appends all the data in MediaItems.txt to itemsVector (if there is enough space)

	/* Format: 
	*	- groups of information about each item are seperated by a single empty line 
	*	- each line of the group contains data about a specific variable for that item
	*   - each group MUST have the correct amount of data/lines (for their item type)
	*   - each piece of data for each item follows this format "{Data Name}: {Data}" (having ": " is crucial)
	*   - data can't be moved around, it has to follow this specific format:
	* 
	*			Book			|		Magazine
	*	 type (str) = "Book"	|  type (str) = "Magazine"
	*	 name (str)				|  name (str)
	*	 amount	(int)			|  amount (int)
	*	 genre (str)			|  company (str)
	*	 author name (str)		|  edition (int)
	*	 author country (str)	|
	*/ 

	string line;

	ifstream MyReadFile(filename);  // Read from the text file
	try {
		while (getline(MyReadFile, line)) {
			vector<string> objectData;
			string type = line;

			while (getline(MyReadFile, line) && !line.empty()) {
				size_t pos = line.find(":");
				objectData.push_back(line.substr(pos + 2, string::npos));  // +2 to account for the space after the ":"
			}

			if (type == "Type: Book")
				addItem(createBookObject(objectData));
			else if (type == "Type: Magazine")
				addItem(createMagazineObject(objectData));
			else
				throw invalid_argument("File Read Error! Object type was not Book or Magazine");

		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		exit(0);
	}

	MyReadFile.close();
}

void Library::writeAllData() {
	// writes all the data for each item in the items vector to MediaItems.txt
	// (see readAllData() for formating)

	ofstream MyWriteFile("MediaItems.txt");  // open text file

	for (MediaItem* mi : itemsVector) {
		MyWriteFile << mi->getDetails() << "\n";  // write out data about each item
	}
	
	MyWriteFile.close();  // Close the file
}

// ================ Display Functions ================

void Library::displayItems() {
	cout << "=================================\n";
	cout << "Unique items (not including copies): " << itemsVector.size() << "\n";
	cout << "Total items (including copies): " << countItemsInVector() << "\n";

	// using a for-loop to iterate through the vector
	for (MediaItem* mi : itemsVector)
		cout << endl << mi->getDetails();
	
	cout << "=================================\n\n";
}

void Library::displayItemsWithName(string givenName) {
	givenName = lowerString(givenName);
	cout << "=================================\n";
	cout << "Items with name: \"" << givenName << "\"\n";
	for (MediaItem* mi : itemsVector) {
		// compare lowered strings
		if (lowerString(mi->getName()) == givenName)
			cout << endl << mi->getDetails();
	}
	cout << "=================================\n\n";
}

void Library::displayItemsWithAuthor(string givenCreator) {
	givenCreator = lowerString(givenCreator);
	cout << "=================================\n";
	cout << "Items with author/company name: \"" << givenCreator << "\"\n";
	for (MediaItem* mi : itemsVector) {
		// compare lowered strings
		if (lowerString(mi->getCreatorName()) == givenCreator)
			cout << endl << mi->getDetails();
	}
	cout << "=================================\n\n";
}

ostream& operator<<(ostream& ostr, Library& d) {
	ostr << "Type: Library\n";
	ostr << "Name: " << d.libraryName << "\n";
	ostr << "Item Capacity: " << d.MAXITEMS << "\n\n";
	ostr << "Current item amount: " << d.countItemsInVector() << "\n\n";
	return ostr;
}