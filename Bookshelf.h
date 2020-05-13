// Book header file
#include <iostream>
#include <string>
using namespace std;

#ifndef Book_Header
#define Book_Header

class Bookshelf {
private:
	string title;
	string author;
	string isbn;
	string instock;
public:
	Bookshelf(string title, string author, string isbn, string instock);
	Bookshelf();
	string getTitle();
	string getAuthor();
	string getISBN();
	string getAvailability();
	string setAvailablitiy();
	void toString();
};

#endif // !Book_Header