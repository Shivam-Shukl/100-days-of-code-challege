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
private:
    void solve(TreeNode* root, int k ,bool &ans ,int sum)
    {
        if(root == NULL)
        {
            return;
        }
        
        sum = sum+ root->val;
        if(root -> left == NULL && root->right == NULL)
        {
            if(sum == k)
            {
                ans=true;
            }
        }
        solve(root->left,k,ans,sum);
        solve(root->right,k,ans,sum);

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        solve(root,targetSum,ans,0);
        return ans;
    }
};