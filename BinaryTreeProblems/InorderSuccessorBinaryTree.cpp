#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

Node *InorderSuccIterative(Node *root, int val)
{
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;

    InorderSuccIterative(root, 10);

    return 0;
}