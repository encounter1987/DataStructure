#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST.h"

using namespace std;


// Simple brute force solution
// find depth of key1
// find depth of key2
// find depth of lca for key1 && key2
// result = dkey1 + dkey2 - 2*dlca


int distanceBetweenNodes(Node* root, const int key1, const int key2, bool& foundLca)
{
    if(root == nullptr)
        return 0;

    if(root->left == nullptr && root->right == nullptr &&
       (root->data == key1 || root->data == key2))
       {
            if(key1 == key2)
            {
                foundLca = true;
                return 0;
            }

            return 1;
       }

    int ld = distanceBetweenNodes(root->left, key1, key2, foundLca);
    int rd = distanceBetweenNodes(root->right, key1, key2, foundLca);

    int curr = (int)(root->data == key1 || root->data == key2);

    foundLca = foundLca || 
             (ld && rd) || 
           (ld && curr) || 
           (rd && curr) || 
           (curr && key1 == key2);

    return  foundLca ? ld + rd :
            ld || rd ? max(ld, rd) + 1 : curr;     
}


int main()
{
    Node *root = NULL;
    DeSerialize(root, "Input"); // 1 2 4 ) ) 5 ) ) 3 6 ) 8 ) ) 7 ) )
    DrawBinaryTree(root);
    cout << endl;

    bool foundLca = false;
    cout << "(4, 5) -> " << distanceBetweenNodes(root, 4, 5, foundLca) << endl;
    foundLca = false;
    cout << "(4, 6) -> " << distanceBetweenNodes(root, 4, 6, foundLca) << endl;
    foundLca = false;
    cout << "(3, 4) -> " << distanceBetweenNodes(root, 3, 4, foundLca) << endl;
    foundLca = false;
    cout << "(2, 4) -> " << distanceBetweenNodes(root, 2, 4, foundLca) << endl;
    foundLca = false;
    cout << "(8, 5) -> " << distanceBetweenNodes(root, 8, 5, foundLca) << endl;
    foundLca = false;
    cout << "(6, 6) -> " << distanceBetweenNodes(root, 6, 6, foundLca) << endl;

    return 0;
}