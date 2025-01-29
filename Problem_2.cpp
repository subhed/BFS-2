// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: Cousins in Binary Tree
// Approach: BFS
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
    bool isCousins(TreeNode *root, int x, int y)
    {
        // Base Case
        if (root == NULL)
        {
            return false;
        }

        // Queue for BFS
        queue<pair<TreeNode *, TreeNode *>> q;

        // Push root node into queue
        q.push({root, nullptr});

        while (!q.empty())
        {
            int size = q.size();
            TreeNode *parentX = nullptr, *parentY = nullptr;

            // Loop around nodes in the queue
            for (int i = 0; i < size; i++)
            {
                auto [node, parent] = q.front();
                q.pop();

                // Check if matches x or y
                if (node->val == x)
                {
                    parentX = parent;
                }
                if (node->val == y)
                {
                    parentY = parent;
                }

                // Push child into the queue
                if (node->left)
                {
                    q.push({node->left, node});
                }
                if (node->right)
                {
                    q.push({node->right, node});
                }
            }

            // If both x and y are found at the same level, check their parents
            if (parentX && parentY)
            {
                return parentX != parentY;
            }

            // If only one is found, they are not cousins
            if (parentX || parentY)
            {
                return false;
            }
        }

        return false;
    }
};