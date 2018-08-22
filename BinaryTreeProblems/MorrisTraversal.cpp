#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

void MorrisPreorder(Node *root)
{
    while (root != nullptr)
    {
        if (root->left != nullptr)
        {
            Node *inorderPredecessor = root->left;

            while (inorderPredecessor->right != nullptr && inorderPredecessor->right != root)
                inorderPredecessor = inorderPredecessor->right;

            if (inorderPredecessor->right == root)
            {
                inorderPredecessor->right = nullptr;
                root = root->right;
            }
            else
            {
                cout << root->data << " ";
                inorderPredecessor->right = root;
                root = root->left;
            }
        }
        else
        {
            cout << root->data << " ";
            root = root->right;
        }
    }
}

void MorrisInorder(Node *root)
{
    while (root != nullptr)
    {
        if (root->left != nullptr)
        {
            Node *inorderPredecessor = root->left;

            while (inorderPredecessor->right != nullptr && inorderPredecessor->right != root)
                inorderPredecessor = inorderPredecessor->right;

            if (inorderPredecessor->right == root)
            {
                cout << root->data << " ";
                inorderPredecessor->right = nullptr;
                root = root->right;
            }
            else
            {
                inorderPredecessor->right = root;
                root = root->left;
            }
        }
        else
        {
            cout << root->data << " ";
            root = root->right;
        }
    }
}

void print_reverse(Node *start, Node *end)
{
    vector<int> cur;
    for (Node *i = start; i != end; i = i->right)
    {
        cur.push_back(i->data);
    }

    for (int i = cur.size() - 1; i >= 0; i--)
        cout << cur[i] << " ";
}

void MorrisPostorder(Node *root)
{
    Node *dummy = new Node(-1);
    dummy->left = root;
    root = dummy;

    while (root != nullptr)
    {
        if (root->left != nullptr)
        {
            Node *inorderPredecessor = root->left;

            while (inorderPredecessor->right != nullptr && inorderPredecessor->right != root)
                inorderPredecessor = inorderPredecessor->right;

            if (inorderPredecessor->right == root)
            {
                // print_reverse left to right
                print_reverse(root->left, root);
                inorderPredecessor->right = nullptr;
                root = root->right;
            }
            else
            {
                inorderPredecessor->right = root;
                root = root->left;
            }
        }
        else
        {
            root = root->right;
        }
    }
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;

    cout << "MorrisPreorder: ";
    MorrisPreorder(root);
    cout << endl;

    cout << "MorrisInorder: ";
    MorrisInorder(root);
    cout << endl;

    cout << "MorrisPostorder: ";
    MorrisPostorder(root);
    cout << endl;

    return 0;
}