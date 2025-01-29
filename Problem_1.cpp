// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: Bianry Tree Right Side View
// Approach: DFS
// Time Complexity: O(n)
// Space Complexity: O(n)

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
class Solution
{
public:
    vector<int> result;

    vector<int> rightSideView(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return result;
        }

        dfs(root, 0);

        return result;
    }

    void dfs(TreeNode *root, int depth)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        // Check array size if depth was ever reached, if yes then replace the value
        if (result.size() >= depth + 1)
        {
            result[depth] = root->val;
        }
        // Push the value into vector as we have reached this depth for the first time
        else
        {
            result.push_back(root->val);
        }

        // Run DFS on the child nodes
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);

        return;
    }
};