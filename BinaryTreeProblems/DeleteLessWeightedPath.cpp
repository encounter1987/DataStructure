/*
Sum of key elements in individual path of BST (just say this sum as path_ weight) and threshold path weight is given as input.
If any of the pathweight is less than oversold path weight then that should be deleted from the tree.

Input:

Threshold: 180

            50
           /  \
         30    70
       /   \   /  \
     20    40 50  80
            \   \
            10  10      

Output tree:

            50
              \
               70
              /  \
             50  80
              \
               10

*/

#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

bool DeleteLessWeightedPath(Node *root, int weight, int &thresold)
{
    if (root == nullptr)
    {
        return false; // not part of correct path
    }

    weight += root->data;

    if (root->left == nullptr && root->right == nullptr)
    {
        return weight >= thresold;
    }

    bool left = DeleteLessWeightedPath(root->left, weight, thresold);
    bool right = DeleteLessWeightedPath(root->right, weight, thresold);

    if (!left && root->left != nullptr)
    {
        delete root->left;
        root->left = nullptr;
    }

    if (!right && root->right != nullptr)
    {
        delete root->right;
        root->right = nullptr;
    }

    return left || right;
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;

    int threshold = 180;
    if (!DeleteLessWeightedPath(root, 0, threshold))
    {
        delete root;
        root = nullptr;
    }

    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;

    return 0;
}