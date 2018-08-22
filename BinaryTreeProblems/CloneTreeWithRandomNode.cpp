#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);

    printf("[(%p) %d, ", root, root->data);
    root->random ? printf("(%p) %d] ", root->random, root->random->data) : printf("(NULL)] ");

    inorder(root->right);
}

void Clone(Node *root, Node *&clone, map<Node *, Node *> &m)
{
    if (root == nullptr)
        return;

    clone = new Node(root->data);
    m[root] = clone;

    Clone(root->left, clone->left, m);
    Clone(root->right, clone->right, m);

    clone->random = m[root->random];
}

int main()
{
    // Variation 1
    // Input for this problem
    // 1 2 4 ) ) ) 3 5 7 ) ) ) 6 8 ) )
    Node *root = NULL;
    DeSerialize(root, "InputClone");

    // Create random link
    root->random = root->right->left->left;
    root->right->right->left->random = root;

    DrawBinaryTree(root);
    cout << "Orginal tree:\n";
    inorder(root);
    cout << endl;

    Node *clone = nullptr;
    map<Node *, Node *> m;
    Clone(root, clone, m);

    cout << "Cloned tree:\n";
    inorder(clone);
    cout << endl;

    cout << "Orginal tree:\n";
    inorder(root);
    cout << endl;

    return 0;
}