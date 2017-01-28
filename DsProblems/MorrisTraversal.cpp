#include "BST.h"
#include<iostream>
#include<stdio.h>
#include<limits.h>

using namespace std;

void MorrisInorderTraversal(Node* root)
{
	cout << "Morris inorder traversal :\n";
	Node* curr = root;

	while(curr != NULL)
	{
		if( curr->left == NULL)
		{
			cout << curr->data<<" ";
			curr = curr->right;
		}
		else
		{
			// Find inorder predecessor of curr;
			Node* predecessor = curr->left;

			while( predecessor->right != curr && predecessor->right != NULL)
			{
				predecessor = predecessor->right;
			}

			if(predecessor->right == NULL)
			{
				predecessor->right = curr;
				curr = curr->left;
			}
			else // left subtree of curr has been traversed. Now visit curr.
			{
				cout << curr->data<<" ";
				curr = curr->right;
				
				// Fix the right link, as it was before creating the link.
				predecessor->right = NULL;
			}
		}
	}

	cout<<endl;
}


void MorrisPreorderTraversal(Node* root)
{
	cout << "Morris preorder traversal :\n";
	Node* curr = root;

	while(curr != NULL)
	{
		if( curr->left == NULL)
		{
			cout << curr->data<<" ";
			curr = curr->right;
		}
		else
		{
			// Find inorder predecessor of curr;
			Node* predecessor = curr->left;

			while( predecessor->right != curr && predecessor->right != NULL)
			{
				predecessor = predecessor->right;
			}

			if(predecessor->right == NULL)
			{
				cout << curr->data<<" ";
				predecessor->right = curr;
				curr = curr->left;
			}
			else // left subtree of curr has been traversed. Now visit curr.
			{
				curr = curr->right;
				
				// Fix the right link, as it was before creating the link.
				predecessor->right = NULL;
			}
		}
	}

	cout<<endl;
}

int main()
{
	Node* root = NULL;
	deSerialize(root);
	drawBinaryTree(root);

	MorrisInorderTraversal(root);
	MorrisPreorderTraversal(root);

	return 0;
}
