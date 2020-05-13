#include <iostream>
#include <string>
#include "Bookshelf.h"
using namespace std;

// Book Binary Tree
struct isbnNode {
	Bookshelf *data;
	isbnNode *left;
	isbnNode *right;
};

isbnNode *createisbn(Bookshelf *data) {
	isbnNode *temp = new isbnNode;
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

void insertisbn(isbnNode *&nroot, Bookshelf *data) {
	if (nroot == NULL) {
		nroot = createisbn(data);
	}
	else if (data->getISBN() < nroot->data->getISBN()) {
		insertisbn(nroot->left, data);
	}
	else {
		insertisbn(nroot->right, data);
	}
}

isbnNode* searchbyisbn(isbnNode *nroot, string isbn) {
	if (nroot == NULL) {
		return nroot;
	}
	else if (nroot->data->getISBN() == isbn) {
		nroot->data->toString();
		return nroot;
	}
	else if (isbn < nroot->data->getISBN()) {
		return searchbyisbn(nroot->left, isbn);
	}
	else {
		return searchbyisbn(nroot->right, isbn);
	}
}

isbnNode* rentbyisbn(isbnNode *nroot, string isbn) {
	if (nroot == NULL) {
		return nroot;
	}
	else if (nroot->data->getISBN() == isbn) {
		return nroot;
	}
	else if (isbn < nroot->data->getISBN()) {
		return rentbyisbn(nroot->left, isbn);
	}
	else {
		return rentbyisbn(nroot->right, isbn);
	}
}

