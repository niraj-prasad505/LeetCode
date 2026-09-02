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
    bool helper(TreeNode* root, int targetSum, int currentSum) {
        if (root == nullptr)
            return false;

        currentSum += root->val;

        if (root->left == nullptr && root->right == nullptr)
            return currentSum == targetSum;

        bool x1 = helper(root->left, targetSum, currentSum);
        bool x2 = helper(root->right, targetSum, currentSum);

        return x1 || x2;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }
};