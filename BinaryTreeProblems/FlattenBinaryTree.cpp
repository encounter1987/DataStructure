/*
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.
*/
#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

Node *fun(Node *root)
{
    if (root == nullptr ||
        root->left == nullptr && root->right == nullptr)
        return root;

    Node *left = fun(root->left);
    Node *right = fun(root->right);

    if (left != nullptr)
    {
        left->right = root->right;
        root->right = root->left;
    }
    root->left = nullptr;

    return right == nullptr ? left : right;
}

Node *flatten(Node *root)
{
    fun(root);

    return root;
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;
    root = flatten(root);
    DrawBinaryTree(root);

    return 0;
}