#include <iostream>
#include <string>
#include "Bookshelf.h"
using namespace std;

// Book Binary Tree
struct authorNode {
	Bookshelf *data;
	authorNode *left;
	authorNode *right;
};

authorNode *createauthor(Bookshelf *data) {
	authorNode *temp = new authorNode;
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

void insertauthor(authorNode *&root, Bookshelf *data) {
	if (root == NULL) {
		root = createauthor(data);
	}
	else if (data->getAuthor() < root->data->getAuthor()) {
		insertauthor(root->left, data);
	}
	else {
		insertauthor(root->right, data);
	}
}

void searchbyauthor(authorNode *root, string author) {
	if (root == NULL) {
		
	}
	else if (root->data->getAuthor() == author) {
		root->data->toString();
		searchbyauthor(root->left, author);
		searchbyauthor(root->right, author);
	}
	else if (author < root->data->getAuthor()) {
		return searchbyauthor(root->left, author);
	}
	else {
		return searchbyauthor(root->right, author);
	}
}

