/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int CountNodes(struct TreeNode* root) {
        // base case
        if (root == NULL) {
            return 0;
        }
        int ans = 1 + CountNodes(root->left) + CountNodes(root->right);
        return ans;
    }
    bool isCBT(struct TreeNode* root, int index, int cnt) {
        if (root == NULL) {
            return true;
        }
        if (index >= cnt) {
            return false;
        } else {
            bool left = isCBT(root->left, 2 * index + 1, cnt);
            bool right = isCBT(root->right, 2 * index + 2, cnt);
            return (left && right);
        }
    }
    

public:
    bool isCompleteTree(TreeNode* root) {
        int index = 0;
        int totalCount = CountNodes(root);
        bool ans = isCBT(root,index,totalCount);
        return ans;
    }
};