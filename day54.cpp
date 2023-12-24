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
class Solution
{
public:
    void MorrisTraversal(TreeNode *root,vector<int> &v)
    {
        TreeNode *current, *pre;

        if (root == NULL)
            return;

        current = root;
        while (current != NULL)
        {

            if (current->left == NULL)
            {
                v.push_back(current->val);
                current = current->right;
            }
            else
            {

                /* Find the inorder predecessor of current */
                pre = current->left;
                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;

                /* Make current as the right child of its
                   inorder predecessor */
                if (pre->right == NULL)
                {
                    pre->right = current;
                    current = current->left;
                }

                /* Revert the changes made in the 'if' part to
                   restore the original tree i.e., fix the right
                   child of predecessor */
                else
                {
                    pre->right = NULL;
                    v.push_back(current->val);
                    current = current->right;
                } /* End of if condition pre->right == NULL */
            }     /* End of if condition current->left == NULL*/
        }         /* End of while */
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        MorrisTraversal(root,ans);
        return ans;
    }
};