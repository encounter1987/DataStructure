#include <iostream>
#include "BinaryTree.h"

using namespace std;

struct Info
{
    int subTreeSum;
    bool isSumTree;

    Info(int val, bool t) : subTreeSum(val), isSumTree(t)
    {
    }

    operator bool()
    {
        return isSumTree;
    }
};

Info IsSumTree(Node *root)
{
    if (root == nullptr)
    {
        return Info(0, true);
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return Info(root->data, true);
    }

    Info left = IsSumTree(root->left);
    Info right = IsSumTree(root->right);

    if (left && right && root->data == left.subTreeSum + right.subTreeSum)
    {
        return Info(root->data + left.subTreeSum + right.subTreeSum, true);
    }

    return Info(0, false);
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;

    IsSumTree(root) ? cout << "Sum tree\n" : cout << "Not Sum tree\n";

    return 0;
}