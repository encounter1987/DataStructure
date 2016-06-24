#include "BinaryTree.h"
#include<iostream>
#include<stdio.h>

using namespace std;


int main()
{
	Node* root = NULL;
	deSerialize(root);

	drawBinaryTree(root);
	cout << endl;

	return 0;
}
