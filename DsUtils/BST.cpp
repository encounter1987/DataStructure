#include "BST.h"

#include <iostream>

using namespace std;

static Node* newNode(int val)
{
	Node* _new = new Node();
	_new->data = val;
	_new->left = NULL;
	_new->right = NULL;

	return _new;
}


void BSTInsert(Node*& root, int data)
{
    if(root == NULL)
    {
        root = newNode(data);

        return;
    }

    Node *parent = NULL, *child = root;

    while(child != NULL)
    {
        parent = child;
        child = data < parent->data ? parent->left : parent->right;
    }

    if(data < parent->data)
        parent->left = newNode(data);
    else
        parent->right = newNode(data);
}
