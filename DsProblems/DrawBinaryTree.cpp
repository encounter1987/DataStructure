#include "BinaryTree.h"
#include "BST.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
	Node* root = NULL;
	//deSerialize(root);
	//
	for( int i = 0; i < 10; ++i)
	{
		BSTInsert(root, rand()%50);
	}

	drawBinaryTree(root);
	Inorder(root);
	cout << endl;

	return 0;
}
