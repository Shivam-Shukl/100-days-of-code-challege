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

class Solution{
public:
    // Function to store the zig zag order traversal of tree in a list.

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> levelValues; // Vector to hold values at each level

            // Level process
            for (int i = 0; i < size; i++)
            {
                TreeNode *FrontNode = q.front();
                q.pop();

                if (leftToRight)
                {
                    levelValues.push_back(FrontNode->val);
                }
                else
                {
                    levelValues.insert(levelValues.begin(), FrontNode->val);
                }

                if (FrontNode->left)
                {
                    q.push(FrontNode->left);
                }
                if (FrontNode->right)
                {
                    q.push(FrontNode->right);
                }
            }

            // Direction change
            leftToRight = !leftToRight;

            // Append levelValues to result
            result.push_back(levelValues);
        }
        return result;
    }
};