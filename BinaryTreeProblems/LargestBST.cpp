#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

struct Info
{
    int size;
    bool isBst;
    int min;
    int max;
    Node *res;
};

Info LargestBst(Node *root)
{
    Info i;

    if (root == nullptr)
    {
        i.size = 0;
        i.isBst = true;
        i.min = INT32_MAX;
        i.max = INT32_MIN;

        return i;
    }

    Info l = LargestBst(root->left);
    Info r = LargestBst(root->right);

    if (l.isBst && r.isBst && l.max < root->data && root->data <= r.min)
    {
        i.isBst = true;
        i.size = l.size + r.size + 1;
        i.min = l.size == 0 ? root->data : l.min;
        i.max = r.size == 0 ? root->data : r.max;
        i.res = root;

        return i;
    }

    i.isBst = false;
    i.size = max(l.size, r.size);
    i.res = l.size > r.size ? root->left : root->right;

    return i;
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;

    Info r = LargestBst(root);

    cout << "Sizeof largest BST = " << r.size << endl;
    DrawBinaryTree(r.res);

    return 0;
}