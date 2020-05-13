#include "Bookshelf.h"

// Object
Bookshelf::Bookshelf(string title, string author, string isbn, string instock) {
	this->title = title;
	this->author = author;
	this->isbn = isbn;
	this->instock = instock;
}

Bookshelf::Bookshelf() {

}

// String Functions
string Bookshelf::getTitle() {
	return title;
}

string Bookshelf::getAuthor() {
	return author;
}

string Bookshelf::getISBN() {
	return isbn;
}

string Bookshelf::getAvailability() {
	return instock;
}

string Bookshelf::setAvailablitiy() {
	if (instock == "available") {
		instock = "unavailable";
		return instock;
	}
	else if (instock == "unavailable") {
		instock = "available";
		return instock;
	}
}

// Void Functions
void Bookshelf::toString() {
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "ISBN: " << isbn << endl;
	cout << "Currently available: " << instock << endl;
	cout << endl;
}