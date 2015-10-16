#include <bits/stdc++.h>
using namespace std;

struct treenode {
	int data;
	treenode *left, *right;
};

void morris(treenode* root) {
	treenode *current = root;
	while (current != NULL) {
		if (current->left == NULL) {
			cout << current->data << ' ';
			current = current->right;
		}
		else {
			treenode* rightmost = current->left;
			while (rightmost->right != NULL && rightmost->right != current)
				rightmost = rightmost->right;
			if (rightmost->right == NULL) {
				rightmost->right = current;
				current = current->left;
			}
			else {
				cout << current->data << ' ';
				current = current->right;
				rightmost->right = NULL;
			}

		}
	}
}

int main() {
	treenode* root = new treenode;
	root->data = 1;
	root->left = new treenode;
	root->right = new treenode;
	root->left->data = 2;
	root->right->data = 3;
	root->left->left = new treenode;
	root->left->left->data = 4;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	root->left->right = new treenode;
	root->left->right->data = 5;
	root->left->right->left = NULL;
	root->left->right->right = NULL;
	root->right->left = new treenode;
	root->right->left->data = 6;
	root->right->left->left = NULL;
	root->right->left->right = NULL;
	root->right->right = new treenode;
	root->right->right->data = 7;
	root->right->right->left = NULL;
	root->right->right->right = NULL;
	morris(root);
	cout << endl;
}
