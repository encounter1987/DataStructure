#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<iostream>

struct Node
{
	int data;
	Node* left, *right;
};

void deSerialize(Node*& root);
void Inorder(Node* root);
void Preorder(Node* root);
void Postorder(Node* root);
void drawBinaryTree(Node* root);
int  GetHeight(Node* root);

#endif
