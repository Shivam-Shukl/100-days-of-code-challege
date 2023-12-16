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


public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;

        if (root == nullptr) {
            return result;
        }

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            pair<TreeNode *, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode *frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);
            for (auto & pair_lvl : nodes[hd]) {
                sort(pair_lvl.second.begin(), pair_lvl.second.end());
            }
 
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        for (auto i : nodes) {
            vector<int> level;
            for (auto j : i.second) {
                for (auto k : j.second) {
                    level.push_back(k);
                }
            }
            result.push_back(level);
        }

        return result;
    }
};
