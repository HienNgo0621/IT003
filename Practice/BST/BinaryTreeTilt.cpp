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
    int dfs(TreeNode* root, int &sum)
    {
        if (!root) return 0;
        int leftNode = dfs(root -> left, sum);
        int rightNode = dfs(root -> right, sum);
        sum += abs(leftNode - rightNode);
        return leftNode + rightNode + root -> val;
    }

    int findTilt(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};
