#include <iostream>
#include <string>
#include "Accounts.h"
#include "Bookshelf.h"
using namespace std;

// Account Binary Tree
struct AccountNode {
	Accounts *newaccount;
	AccountNode *left;
	AccountNode *right;
};

AccountNode *createAccount(Accounts *newaccount) {
	AccountNode *temp = new AccountNode;
	temp->newaccount = newaccount;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

void insertAccount(AccountNode *&accountroot, Accounts *newaccount) {
	if (accountroot == NULL) {
		accountroot = createAccount(newaccount);
	}
	else if (newaccount < accountroot->newaccount) {
		insertAccount(accountroot->left, newaccount);
	}
	else {
		insertAccount(accountroot->right, newaccount);
	}
}

void rent(AccountNode *&accountroot, string email, string password, Bookshelf *book) {
	if (accountroot == NULL) {

	}
	else if (email == accountroot->newaccount->getEmail() && password == accountroot->newaccount->getPassword()) {
		accountroot->newaccount->rent(book);
	}
	else if (email < accountroot->newaccount->getEmail()) {
		rent(accountroot->left, email, password, book);
	}
	else {
		rent(accountroot->right, email, password, book);
	}
}

bool login(AccountNode *accountroot, string email, string password) {
	if (accountroot == NULL) {
		cout << "Account does not exist" << endl;
		system("pause");

		return false;
	}
	else if (email == accountroot->newaccount->getEmail()) {
		if (email == accountroot->newaccount->getEmail() && password == accountroot->newaccount->getPassword()) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (email < accountroot->newaccount->getEmail()) {
		login(accountroot->left, email, password);
	}
	else if (email > accountroot->newaccount->getEmail()) {
		login(accountroot->right, email, password);
	}
}

void displayAccounts(AccountNode *accountroot) { //Inorder
	if (accountroot != NULL) {
		displayAccounts(accountroot->left);
		accountroot->newaccount->toString();
		cout << endl;
		displayAccounts(accountroot->right);
	}
}

void displaydata(AccountNode *accountroot, string email, string password) {
	if (accountroot == NULL) {

	}
	else if (email == accountroot->newaccount->getEmail() && password == accountroot->newaccount->getPassword()) {
		string answer;

		cout << "Name: " << accountroot->newaccount->getName() << endl;
		cout << "Email: " << accountroot->newaccount->getEmail() << endl;
		cout << "Rentals: " << accountroot->newaccount->getRentalNumber() << endl;
		cout << "return a rentals (y/n): ";
		cin >> answer;

		system("cls");

		if (answer == "y" || answer == "Y") {
			
			accountroot->newaccount->getRentals();
		}
		else {

		}
	}
	else if (email < accountroot->newaccount->getEmail()) {
		displaydata(accountroot->left, email, password);
	}
	else {
		displaydata(accountroot->right, email, password);
	}
}