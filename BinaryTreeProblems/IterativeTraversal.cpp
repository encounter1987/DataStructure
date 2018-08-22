#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

void IterativePreorder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *t = st.top();
        st.pop();

        cout << t->data << " ";

        if (t->right)
            st.push(t->right);
        if (t->left)
            st.push(t->left);
    }
}

void IterativeInorder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> st;

#if 0
    st.push(root);

    while (!st.empty())
    {
        while (root != nullptr)
        {
            if (root->left)
                st.push(root->left);
            root = root->left;
        }

        root = st.top();
        st.pop();
        cout << root->data << " ";

        while (!st.empty() && root->right == nullptr)
        {
            root = st.top();
            st.pop();
            cout << root->data << " ";
        }

        root = root->right;

        if (root)
            st.push(root);
    }
#else
    // Optimize code the above while loop
    // Merge duplicate codes

    while (root != nullptr || !st.empty())
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();
        cout << root->data << " ";

        root = root->right;
    }
#endif
}

void IterativePostorder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> st;

    while (root != nullptr || !st.empty())
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }

        Node *temp = st.top();

        if (temp->right == nullptr)
        {
            cout << temp->data << " ";
            st.pop();

            while (!st.empty() && temp == st.top()->right)
            {
                temp = st.top();
                cout << temp->data << " ";
                st.pop();
            }
        }
        else
            root = temp->right;
    }
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;

    cout << "Iterative preorder: ";
    IterativePreorder(root);
    cout << endl;

    cout << "Iterative inorder: ";
    IterativeInorder(root);
    cout << endl;

    cout << "Iterative postorder: ";
    IterativePostorder(root);
    cout << endl;

    return 0;
}