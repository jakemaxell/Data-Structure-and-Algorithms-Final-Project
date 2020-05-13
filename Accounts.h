#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include "Bookshelf.h"
using namespace std;

#ifndef Account_Header
#define Account_Header

class Accounts {
private:
	string name;
	string email;
	string password;
	int accountnumber;
	queue<Bookshelf*> rentals;
public:
	Accounts(string, string, string);
	void toString();
	void rent(Bookshelf *book);
	void getRentals();
	string getName();
	string getEmail();
	string getPassword();
	int getRentalNumber();
};

void createAccount(Accounts *, ofstream*);
#endif
//void rent(vector<Bookshelf*>library, int number);

