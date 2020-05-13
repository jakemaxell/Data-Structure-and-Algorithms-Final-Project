// Final Project: Library
// Author: Jacob Maxwell
// Date last updated: 05/11/2019
// Purpose: To use the concepts learned in Computer Science III to design a library kiosk using datastructures
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Bookshelf.h"
#include "Accounts.h"
#include "titletree.h"
#include "Account Binary Tree.h"
#include "authortree.h"
#include "isbntree.h"
using namespace std;

void importLibrary(fstream &file, Bookshelf *newBook, Node *&root, authorNode *&aroot, isbnNode *&nroot);
void createAccount(ofstream &accountwriting);
bool login(fstream &accountreading, Accounts *newAccount, AccountNode *&accountroot, int &number);

int main() {

	Node *root = NULL;
	authorNode *aroot = NULL;
	isbnNode *nroot = NULL;

	// Bookshelf information
	Bookshelf *newBook = NULL;

	// Account information
	Accounts *newAccount = NULL;
	AccountNode *accountroot = NULL;

	// File input/output information
	fstream librarybooks("Books.txt");
	fstream accountreading("Accounts.txt");
	ofstream accountwriting;

	// Variables
	int choice, account;

	importLibrary(librarybooks, newBook, root, aroot, nroot);


	cout << "     Menu" << endl;
	cout << "--------------" << endl;
	cout << "1. Login" << endl;
	cout << "2. Create account" << endl;
	cout << "3. Exit" << endl;

	cout << "What would you like to do?: ";
	cin >> choice;

	system("cls");

	if (choice == 1) {
		if (login(accountreading, newAccount, accountroot, account) == true) {
			do {
				system("cls");

				cout << "     Menu" << endl;
				cout << "--------------" << endl;
				cout << "1. Search for a book" << endl;
				cout << "2. See account status" << endl;
				cout << "3. Logout" << endl;

				cout << "What would you like to do?: ";
				cin >> choice;

				system("cls");

				if (choice == 1) {
					do {
						system("cls");

						cout << "     Search page" << endl;
						cout << "---------------------" << endl;
						cout << "1. Search by title" << endl;
						cout << "2. Search by author" << endl;
						cout << "3. Search by isbn" << endl;
						cout << "4. List of authors" << endl;
						cout << "5. See entire library" << endl;
						cout << "6. Rent a book" << endl;
						cout << "7. Return to main menu" << endl;

						cout << "What would you like to do?: ";
						cin >> choice;

						system("cls");

						if (choice == 1) {
							cin.ignore();

							string search;

							cout << "What book are you looking for?: ";
							getline(cin, search);

							system("cls");

							searchbytitle(root, search);

							system("pause");
						}
						else if (choice == 2) {
							cin.ignore();

							string search;
							
							cout << "Search by authors full name: ";
							getline(cin, search);

							system("cls");

							cout << search << "'s list of works" << endl;
							cout << "------------------------------------" << endl;
							searchbyauthor(aroot, search);

							system("pause");
						}
						else if (choice == 3) {
							cin.ignore();

							string search;

							cout << "Search by isbn: ";
							getline(cin, search);

							system("cls");

							searchbyisbn(nroot, search);

							system("pause");
						}
						else if (choice == 4) {
							cout << "     List of Authors we have" << endl;
							cout << "---------------------------------" << endl;
							cout << "* Douglas Adams" << endl;
							cout << "* JK Rowling" << endl;
							cout << "* Ken Grimwood" << endl;
							cout << "* Stephen King" << endl;
							cout << "* William Peter Blatty" << endl;

							system("pause");
						}
						else if (choice == 5) {
							
							cout << "     Entire Library" << endl;
							cout << "------------------------" << endl;
							display(root);

							system("pause");
						}
						else if (choice == 6) {
							string search;

							cout << "Rental" << endl;
							cout << "----------------" << endl;
							cout << "1. Rent by isbn" << endl;
							cout << "2. Rent by title" << endl;

							cout << "What would you like to do?: ";
							cin >> choice;

							system("cls");

							if (choice == 1) {
								cout << "Enter isbn: ";
								cin >> search;

								searchbyisbn(nroot, search);

								if (rentbyisbn(nroot, search)->data->getAvailability() == "unavailable") {
									cout << "That title is unavailable" << endl;
								}
								else {
									string email, password;

									cin.ignore();

									cout << "Enter your email: ";
									getline(cin, email);

									cout << "Enter your password: ";
									getline(cin, password);

									rent(accountroot, email, password, rentbyisbn(nroot, search)->data);
									rentbyisbn(nroot, search)->data->setAvailablitiy();

									cout << "That title has been added to your account" << endl;
								}

								system("pause");
							}
							if (choice == 2) {
								cout << "Enter title: ";
								cin >> search;

								searchbytitle(root, search);

									string email, password;

									cin.ignore();

									cout << "Enter your email: ";
									getline(cin, email);

									cout << "Enter your password: ";
									getline(cin, password);

									rent(accountroot, email, password, rentbytitle(root, search)->data);
									rentbytitle(root, search)->data->setAvailablitiy();

									cout << "That title has been added to your account" << endl;

								system("pause");
							}
						}
						else if (choice == 7) {

						}
						else {
							cout << "Invalid input" << endl;
							system("pause");
						}

					} while (choice != 7);
				}
				else if (choice == 2) {
					do {
						system("cls");

						cout << "     Account details" << endl;
						cout << "-------------------------" << endl;
						cout << "1. Account information" << endl;
						cout << "2. Return to menu" << endl;

						cout << "What would you like to do?: ";
						cin >> choice;

						system("cls");

						if (choice == 1) {
							cin.ignore();

							string email, password;

							cout << "Enter your email: ";
							getline(cin, email);

							cout << "Enter your password: ";
							getline(cin, password);

							displaydata(accountroot, email, password);

							system("pause");
						}
						else if (choice == 2) {

						}
						else {
							cout << "Invalid input" << endl;
							system("pause");
						}

					} while (choice != 2);
				}
			} while (choice != 3);

			main();
		}
		else {
			system("cls");

			main();
		}
	}
	else if (choice == 2) {
		createAccount(accountwriting);

		system("cls");

		main();
	}
	else if (choice == 3) {
		return 0;
	}
	else {
		cout << "Invalid input" << endl;

		system("pause");
		system("cls");

		main();
	}

	system("pause");
	return 0;
}

void importLibrary(fstream &file, Bookshelf *newBook, Node *&root, authorNode *&aroot, isbnNode *&nroot) {

		string title, author, isbn, genre;

		while (!file.fail()) {
			getline(file, title);
			getline(file, author);
			getline(file, isbn);
			getline(file, genre);

			newBook = new Bookshelf(title, author, isbn, genre);

			insert(root, newBook);
			insertauthor(aroot, newBook);
			insertisbn(nroot, newBook);
		}
	}
void createAccount(ofstream &accountwriting) {
	cin.ignore();

	string name, email, password, passwordcheck;

	cout << "Enter your name: ";
	getline(cin, name);

	cout << "Enter your email: ";
	getline(cin, email);

	cout << "Create a password: ";
	getline(cin, password);

	cout << "Please verify password: ";
	getline(cin, passwordcheck);

	if (password == passwordcheck) {
		accountwriting.open("Accounts.txt", ios::out | ios::app);
		accountwriting << name << endl;
		accountwriting << email << endl;
		accountwriting << password << endl;
		accountwriting.close();

		cout << "Account created!" << endl;
	}
	else {
		cout << "Passwords did not match" << endl;
	}

	system("pause");
}
bool login(fstream &accountreading, Accounts *newAccount, AccountNode *&accountroot, int &number) {
	cin.ignore();

	number = 0;

	string name, user, pass;
	string email, password;

	while (!accountreading.fail()) {
		getline(accountreading, name);
		getline(accountreading, user);
		getline(accountreading, pass);

		newAccount = new Accounts(name, user, pass);

		insertAccount(accountroot, newAccount);
	}

	cout << "Enter your email: ";
	getline(cin, email);

	cout << "Enter your password: ";
	getline(cin, password);

	return login(accountroot, email, password);
};