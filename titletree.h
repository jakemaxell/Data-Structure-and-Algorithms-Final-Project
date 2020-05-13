#include <iostream>
#include <string>
#include "Bookshelf.h"
using namespace std;

// Book Binary Tree
struct Node {
	Bookshelf *data;
	Node *left;
	Node *right;
};

Node *create(Bookshelf *data) {
	Node *temp = new Node;
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

void insert(Node *&root, Bookshelf *data) {
	if (root == NULL) {
		root = create(data);
	}
	else if (data->getTitle() < root->data->getTitle()) {
		insert(root->left, data);
	}
	else {
		insert(root->right, data);
	}
}

Node* searchbytitle(Node *root, string title) {
	if (root == NULL) {
		cout << "Invalid title" << endl;
		return root;
	}
	else if (title == root->data->getTitle()) {
		root->data->toString();
		return root;
	}
	else if (title < root->data->getTitle()) {
		return searchbytitle(root->left, title);
	}
	else if (title > root->data->getTitle()) {
		return searchbytitle(root->right, title);
	}
}

void searchbyisbn(Node *root, string isbn) {
	if (root == NULL) {
		cout << "Invalid isbn" << endl;
	}
	else if (isbn == root->data->getISBN()) {
		root->data->toString();
	}
	else if (isbn < root->data->getISBN()) {
		searchbyisbn(root->left, isbn);
	}
	else if (isbn > root->data->getISBN()) {
		searchbyisbn(root->right, isbn);
	}
}

Node* rentbytitle(Node *root, string title) {
	if (root == NULL) {
		return root;
	}
	else if (root->data->getTitle() == title) {
		return root;
	}
	else if (title < root->data->getTitle()) {
		return rentbytitle(root->left, title);
	}
	else {
		return rentbytitle(root->right, title);
	}
}

void display(Node *root) {
	if (root == NULL) {

	}
	else {
		root->data->toString();
		display(root->left);
		display(root->right);
	}
}