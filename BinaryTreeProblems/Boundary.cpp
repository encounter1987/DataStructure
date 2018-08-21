#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

void LeftBoundary(Node *root)
{
    if (root == nullptr)
        return;

    if (root->left)
    {
        cout << root->data << " ";
        LeftBoundary(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        LeftBoundary(root->right);
    }
}

void LeafBoundary(Node *root)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
        cout << root->data << " ";

    LeafBoundary(root->left);
    LeafBoundary(root->right);
}

void RightBoundary(Node *root)
{
    if (root == nullptr)
        return;

    if (root->right)
    {
        RightBoundary(root->right);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        RightBoundary(root->left);
        cout << root->data << " ";
    }
}

void Boundary(Node *root)
{
    // Print common area of left and right boundary
    while (root != nullptr && !(root->left != nullptr && root->right != nullptr))
    {
        cout << root->data << " ";
        root = root->left != nullptr ? root->left : root->right;
    }

    if (root == nullptr)
        return;

    LeftBoundary(root);
    LeafBoundary(root->left);
    LeafBoundary(root->right);
    RightBoundary(root->right);
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;

    Boundary(root);

    return 0;
}