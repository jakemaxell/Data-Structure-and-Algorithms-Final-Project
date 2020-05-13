#include "Accounts.h"

// Objects
Accounts::Accounts(string name, string email, string password) {
	this->name = name;
	this->email = email;
	this->password = password;
}

// String functions
string Accounts::getEmail() {
	return email;
}
string Accounts::getName() {
	return name;
}
string Accounts::getPassword() {
	return password;
}

// Int funtions
int Accounts::getRentalNumber() {
	return rentals.size();
}

// Void functions
void Accounts::toString() {
	cout << "Email: " << email << endl;
	cout << "Password: " << password << endl;
}

void Accounts::rent(Bookshelf *book) {
	
	rentals.push(book);
}

void Accounts::getRentals() {
	while (!rentals.empty()) {
		rentals.front()->toString();
		rentals.pop();
	}
}
