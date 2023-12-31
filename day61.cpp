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
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    vector<int> findModes(const std::vector<int>& arr) {
        map<int, int> countMap;

        // Count occurrences of each number
        for (int num : arr) {
            countMap[num]++;
        }

        int maxFrequency = 0;
        std::vector<int> modes;

        // Find the maximum frequency
        for (const auto& pair : countMap) {
            if (pair.second > maxFrequency) {
                maxFrequency = pair.second;
            }
        }

        // Collect all numbers with maximum frequency as modes
        for (const auto& pair : countMap) {
            if (pair.second == maxFrequency) {
                modes.push_back(pair.first);
            }
        }

        return modes;
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        vector<int> ans= findModes(v);
        return ans;
    }
};