#include "BinaryTree.h"
#include "BST.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Node *InorderSucc(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;

    Node *parent = nullptr, *curr = root;

    while (key != curr->data)
    {
        if (key < curr->data)
        {
            if (curr->left ==)

                parent = curr;
            curr = curr->left;
        }
    }

    return nullptr;
}

int main()
{
    // Variation 2
    Node *root = NULL;

    int arr[] = {10, 5, 15, 1, 8, 12, 7, 9};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        BSTInsert(root, arr[i]);
    }

    DrawBinaryTree(root);
    cout << endl;

    Node *res = nullptr;

    int in[] = {1, 5, 8, 9, 12, 15, 10};

    for (int i = 0; i < sizeof(in) / sizeof(in[0]); ++i)
    {
        res = InorderSucc(root, in[i]);

        if (res != nullptr)
            cout << in[i] << "->" << res->data << endl;
        else
            cout << in[i] << "->"
                 << "NULL" << endl;
    }

    return 0;
}
