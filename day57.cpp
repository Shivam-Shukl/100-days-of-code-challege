/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root-> left, v);
        v.push_back(root ->val);
        inorder(root -> right, v);
    }
    TreeNode* inorderToBst(int s, int e, vector<int> &v)
    {
        //base case
        if(s > e )
        return NULL;

        int mid = (s+e)/2;
        TreeNode *root = new TreeNode(v[mid]);
        root -> left = inorderToBst(s,mid-1,v);
        root -> right = inorderToBst(mid+1, e,v);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return inorderToBst(0,v.size()-1,v);

    }
};