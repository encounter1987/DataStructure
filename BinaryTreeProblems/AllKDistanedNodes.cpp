/**
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.
Input level order: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct info {
    int height;
    bool found;
    
    info(int height, int found): height(height), found(found)
    {
    }
};

info heightAndDirection(TreeNode* root, 
                        TreeNode* target, 
                        vector<TreeNode*>& dir, 
                        int level)
{
    if(root == nullptr)
        return info(-1, false);
    
    if(root == target)
    {
        dir.resize(level);

        return info(0, true);
    }
    
    info lh = heightAndDirection(root->left, target, dir, level + 1);    
    info rh = heightAndDirection(root->right, target, dir, level + 1);

    if(lh.found || rh.found)
        dir[level] = lh.found ? root->left : root->right;
    
    if(max(lh.height, rh.height) >= 0)
        return info(1 + max(lh.height, rh.height), lh.found || rh.found);
    
    return info(-1, false);
}

void distance(TreeNode* root, 
              vector<int>& res, 
              int k, 
              int height, 
              vector<TreeNode*>& dir, 
              int level) {
    
    if(root == nullptr)
        return;
    
    if(height == k)
        res.push_back(root->val);
    
    int lh = level < dir.size() && dir[level] == root->left ? -1:1;
    int rh = level < dir.size() && dir[level] == root->right ? -1:1;
    
    distance(root->left, res, k, height + lh, dir, level + 1);
    distance(root->right, res, k, height + rh, dir, level + 1);    
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> dir;
        info is = heightAndDirection(root, target, dir, 0);
        vector<int> res;
        /*
        cout << is.height << " "<<is.found<<endl;
        for(int i = 0; i < dir.size(); ++i)
            cout<< dir[i]->val<<" ";
        cout<<endl;
        */
        distance(root, res, K, is.height, dir, 0);
        
        return res;
    }
};
