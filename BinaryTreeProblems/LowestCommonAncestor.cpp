#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

// Assumed both keys are present in tree
Node *LCA(Node *root, const int &key1, const int &key2)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == key1 || root->data == key2)
        return root;

    Node *left = LCA(root->left, key1, key2);
    Node *right = LCA(root->right, key1, key2);

    if (left != nullptr && right != nullptr)
        return root;

    if (left != nullptr)
        return left;

    if (right != nullptr)
        return right;

    return nullptr;
}

bool LCA(Node *root, const int &key1, const int &key2, Node *&res)
{
    if (root == nullptr)
        return false;

    if (root->left == nullptr && root->right == nullptr &&
        (root->data == key1 || root->data == key2))
    {
        if (key1 == key2) // Handle the case having duplicate values
            res = root;

        return true;
    }

    bool L = LCA(root->left, key1, key2, res);
    bool R = LCA(root->right, key1, key2, res);

    bool curr = root->data == key1 || root->data == key2;

    if ((L && R) ||
        (L && curr) ||
        (R && curr))
    {
        res = root;
        return true;
    }

    return L || R || curr;
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;

    // Approch 1
    // Assumed both keys are present in tree
    Node *r = LCA(root, 2, 5);
    cout << "(2, 5)->" << (r != nullptr ? r->data : -1) << endl;

    r = LCA(root, 2, 8);
    cout << "(2, 8)->" << (r != nullptr ? r->data : -1) << endl;

    r = LCA(root, 13, 7);
    cout << "(13, 7)->" << (r != nullptr ? r->data : -1) << endl
         << endl;

    // Approch 2
    // Not sure keys are present in tree
    Node *res = nullptr;
    LCA(root, 2, 5, res);
    cout << "(2, 5)->" << (res != nullptr ? res->data : -1) << endl;

    res = nullptr;
    LCA(root, 2, 8, res);
    cout << "(2, 8)->" << (res != nullptr ? res->data : -1) << endl;

    res = nullptr;
    LCA(root, 13, 7, res);
    cout << "(13 7)->" << (res != nullptr ? res->data : -1) << endl;

    res = nullptr;
    LCA(root, 13, 20, res);
    cout << "(13, 20)->" << (res != nullptr ? res->data : -1) << endl;

    res = nullptr;
    LCA(root, 13, 13, res);
    cout << "(13, 13)->" << (res != nullptr ? res->data : -1) << endl;

    res = nullptr;
    LCA(root, 1, 1, res);
    cout << "(1, 1)->" << (res != nullptr ? res->data : -1) << endl;

    return 0;
}
