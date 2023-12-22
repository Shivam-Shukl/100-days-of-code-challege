class Solution {
private:
    int Findposition(int in[], int inorderStart, int inorderEnd, int element, int n) {
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (in[i] == element) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n) {
        if (index >= n || inorderStart > inorderEnd) {
            return nullptr;
        }

        int element = pre[index++]; // At every iteration index is increasing
        TreeNode* root = new TreeNode(element);
        int position = Findposition(in, inorderStart, inorderEnd, element, n);

        root->left = solve(in, pre, index, inorderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0 || inorder.size() != n) {
            return nullptr;
        }

        int preorderindex = 0;  // Preorder is NLR so the first element is root.

        TreeNode* ans = solve(&inorder[0], &preorder[0], preorderindex, 0, n - 1, n);
        return ans;
    }
};