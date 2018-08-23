#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

struct Node
{
    int data;
    Node *left, *right;
    Node *random;

    Node() : left(nullptr), right(nullptr), random(nullptr)
    {
    }

    Node(int data) : data(data), left(nullptr), right(nullptr), random(nullptr)
    {
    }
};

void DeSerialize(Node *&root, const std::string &file);
void Inorder(Node *root);
void Preorder(Node *root);
void Postorder(Node *root);
void DrawBinaryTree(Node *root);
int GetHeight(Node *root);

#endif
