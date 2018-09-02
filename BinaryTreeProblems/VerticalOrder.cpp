#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;

typedef vector<int> vec;
typedef vector<vec> Map;

// Recursive solution but each vertical set is not ordered respective to their depth
void func(Node *root, int pos, Map &left, Map &right)
{
    if (root == nullptr)
        return;

    if (pos >= 0)
    {
        if (right.size() <= pos)
            right.push_back(vec());

        right[pos].push_back(root->data);
    }
    else
    {

        int in_pos = (-(pos)) - 1;
        if (left.size() <= in_pos)
            left.push_back(vec());

        left[in_pos].push_back(root->data);
    }

    func(root->left, pos - 1, left, right);
    func(root->right, pos + 1, left, right);
}

Map verticalOrderTraversalRecursive(Node *root)
{
    Map left;
    Map right;

    func(root, 0, left, right);

    std::reverse(left.begin(), left.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}

// Iterative solution but each vertical set is ordered respective to their depth
struct info
{
    Node *node;
    int dist;

    info(Node *t, int dist) : node(t), dist(dist)
    {
    }
};

typedef queue<info> Q;

Map verticalOrderTraversalIterative(Node *root)
{
    Map left;
    Map right;

    if (root == nullptr)
        return left;

    Q q;
    q.push(info(root, 0));

    while (!q.empty())
    {
        info i = q.front();
        q.pop();

        if (i.dist >= 0)
        {
            if (i.dist >= right.size())
                right.push_back(vec());

            right[i.dist].push_back((i.node)->data);
        }
        else
        {
            int mdist = (-(i.dist)) - 1;

            if (mdist >= left.size())
                left.push_back(vec());

            left[mdist].push_back((i.node)->data);
        }

        if ((i.node)->left != nullptr)
        {
            q.push(info((i.node)->left, i.dist - 1));
        }

        if ((i.node)->right != nullptr)
        {
            q.push(info((i.node)->right, i.dist + 1));
        }
    }

    std::reverse(left.begin(), left.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}

int main()
{
    // Variation 1
    Node *root = NULL;
    DeSerialize(root, "Input");
    DrawBinaryTree(root);
    cout << endl;

    Map m = verticalOrderTraversalRecursive(root);

    for (int i = 0; i < m.size(); ++i)
    {
        for (int j = 0; j < m[i].size(); ++j)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----------------------------------------------\n";

    m = verticalOrderTraversalIterative(root);

    for (int i = 0; i < m.size(); ++i)
    {
        for (int j = 0; j < m[i].size(); ++j)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}