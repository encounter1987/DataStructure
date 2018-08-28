/*
* Assumed if the the tree has only one node(root) then the sum equels to the value of that node.
*/
#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

int SumLeftLeaf(Node *root, Node *parent)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr &&
        (parent == nullptr || parent->left == root))
        return root->data;

    return SumLeftLeaf(root->left, root) + SumLeftLeaf(root->right, root);
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;

    cout << "Sum of all left leaf child := " << SumLeftLeaf(root, nullptr) << endl;

    return 0;
}