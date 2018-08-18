#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

void LeftViewIterative(Node *root)
{
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        int len = Q.size();

        for (int i = 1; i <= len; ++i)
        {
            Node *t = Q.front();
            Q.pop();

            if (i == 1)
            {
                cout << t->data << " ";
            }

            if (t->left != nullptr)
                Q.push(t->left);

            if (t->right != nullptr)
                Q.push(t->right);
        }
    }
}

void LeftViewRecursive(Node *root, int levelOfNode, int &prevLevel)
{
    if (root == nullptr)
        return;

    if (levelOfNode > prevLevel)
    {
        cout << root->data << " ";
        prevLevel = levelOfNode;
    }

    LeftViewRecursive(root->left, levelOfNode + 1, prevLevel);
    LeftViewRecursive(root->right, levelOfNode + 1, prevLevel);
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    Inorder(root);
    cout << endl;

    LeftViewIterative(root);
    cout << endl;
    int level = -1;
    LeftViewRecursive(root, 0, level);

    return 0;
}