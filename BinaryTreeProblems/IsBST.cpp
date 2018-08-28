#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

bool IsBst(Node *root, int left, int right)
{
    if (root == nullptr)
        return true;

    if (root->data <= left || root->data > right)
        return false;

    return IsBst(root->left, left, root->data) && IsBst(root->right, root->data, right);
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;

    IsBst(root, INT32_MIN, INT32_MAX) ? printf("Given tree is BST \n") : printf("Given tree is not BST \n");
    //IsBst(root, ) ? printf("Given tree is BST \n") : printf("Given tree is not BST \n");

    return 0;
}