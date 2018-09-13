/* You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list. */

#include <bits/stdc++.h>
#include <BinaryTree.h>

using namespace std;

typedef vector<int> vec;

struct SegmentTree
{
    Node *root;
    vec Stree;

    SegmentTree(const vec &A) : root(nullptr)
    {
        int size = ceil(log2(A.size()));
        size = 1 << size;
        size = 2 * size - 1;

        Stree.resize(size);
        buildTree(A, 0, A.size() - 1, 0);

        root = buildBinaryTree(0, A.size() - 1, 0);
    }

    int Query(int infront, int left, int right, int pos);
    void Update(const int &index, int left, int right, int pos);

    void Draw()
    {
        DrawBinaryTree(root);
    }

  private:
    int buildTree(const vec &A, int left, int right, int pos);
    Node *buildBinaryTree(int left, int right, int pos);
    void updateUtil(const int &index, int left, int right, int pos, Node *root);

    inline int Left(int pos)
    {
        return 2 * pos + 1;
    }
    inline int Right(int pos)
    {
        return 2 * pos + 2;
    }
    inline int Mid(int left, int right)
    {
        return (left + right) / 2;
    }
};

int SegmentTree::buildTree(const vec &A, int left, int right, int pos)
{
    if (left > right)
        return 0;

    if (left == right)
    {
        this->Stree[pos] = 1;

        return this->Stree[pos];
    }

    int mid = Mid(left, right);

    int l = buildTree(A, left, mid, Left(pos));
    int r = buildTree(A, mid + 1, right, Right(pos));

    this->Stree[pos] = l + r;

    return this->Stree[pos];
}

Node *SegmentTree::buildBinaryTree(int left, int right, int pos)
{
    Node *root = new Node(this->Stree[pos]);

    if (left == right)
        return root;

    int mid = Mid(left, right);

    root->left = buildBinaryTree(left, mid, Left(pos));
    root->right = buildBinaryTree(mid + 1, right, Right(pos));

    return root;
}

int SegmentTree::Query(int infront, int left, int right, int pos)
{
    if (left > right)
        return -1;

    if (left == right)
        return left;

    int mid = Mid(left, right);
    int availableSpaceInleft = this->Stree[Left(pos)];

    if (availableSpaceInleft >= infront)
        return Query(infront, left, mid, Left(pos));
    else
        return Query(infront - availableSpaceInleft, mid + 1, right, Right(pos));
}

void SegmentTree::updateUtil(const int &index, int left, int right, int pos, Node *root)
{
    if (left > right)
        return;

    this->Stree[pos]--;
    root->data--;

    if (left == right)
        return;

    int mid = Mid(left, right);

    if (index <= mid)
    {
        updateUtil(index, left, mid, Left(pos), root->left);
    }
    else
    {
        updateUtil(index, mid + 1, right, Right(pos), root->right);
    }
}

void SegmentTree::Update(const int &index, int left, int right, int pos)
{
    updateUtil(index, left, right, pos, this->root);
}

int main()
{
    vec height = {5, 7, 6, 5, 4, 7};
    vec infront = {0, 0, 1, 2, 3, 1};

    vector<pair<int, int>> people(height.size());

    for (int i = 0; i < height.size(); ++i)
        people[i] = pair<int, int>(height[i], infront[i]);

    sort(people.begin(), people.end());

    for (int i = 0; i < height.size(); ++i)
    {
        height[i] = people[i].first;
        infront[i] = people[i].second;
    }

    SegmentTree st(height);
    st.Draw();

    vec res(height.size());

    for (int i = 0; i < height.size(); ++i)
    {
        int idx = st.Query(infront[i] + 1, 0, height.size() - 1, 0);
        st.Update(idx, 0, height.size() - 1, 0);

        res[idx] = height[i];
    }

    for (int i = 0; i < height.size(); ++i)
        cout << res[i] << " ";

    return 0;
}