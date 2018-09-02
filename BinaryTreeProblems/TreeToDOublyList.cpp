#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

void TreeToDoublyList(Node *root, Node *&predessor, Node *&Head, Node *&Tail)
{
    if (root == nullptr)
        return;

    TreeToDoublyList(root->left, predessor, Head, Tail);

    if (predessor == nullptr)
    {
        Head = root;
    }
    else
    {
        root->left = predessor;
        predessor->right = root;
    }
    predessor = root;
    Tail = root;

    TreeToDoublyList(root->right, predessor, Head, Tail);
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;

    Node *Head = nullptr, *Tail = nullptr, *predessor = nullptr;
    TreeToDoublyList(root, predessor, Head, Tail);

    while (Head != nullptr)
    {
        cout << Head->data << " ";
        Head = Head->right;
    }
    cout << "nullptr ";

    return 0;
}