

class Solution {
private:
    void solve(TreeNode *root, vector<vector<int>> &ans) {
        if (root == nullptr) return; // Check if root is null

        stack<vector<int>> s;
        queue<TreeNode *> Q;
        Q.push(root);
        
        while (!Q.empty()) {
            int levelSize = Q.size();
            vector<int> v;

            for (int i = 0; i < levelSize; i++) {
                TreeNode *temp = Q.front();
                Q.pop();

                v.push_back(temp->val); // Push current node's value

                if (temp->left != nullptr) {
                    Q.push(temp->left); // Push left child
                }
                if (temp->right != nullptr) {
                    Q.push(temp->right); // Push right child
                }
            }
            s.push(v);
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        solve(root, ans);
        return ans;
    }
};
