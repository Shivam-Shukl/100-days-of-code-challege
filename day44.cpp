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
    bool solve(TreeNode* r1,TreeNode* r2)
    {
        if(r1 == NULL && r2 ==NULL)
        {
            return true;
        }
        else if(r1 ==NULL && r2 != NULL)
        {
            return false;
        }
        else if(r1 !=NULL && r2 == NULL)
        {
            return false;
        }
        
        bool left =solve(r1->left,r2->left);
        bool right = solve(r1 -> right ,r2-> right);
        
        bool value = r1->val== r2-> val;
        if(left && right && value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
        
    }
};