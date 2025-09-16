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
    TreeNode* construct(vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr ;
        }
        int mx = INT_MIN ;
        int mxIndex = -1 ;
        for (int i = start ; i <= end ; i++) {
            if (nums[i] > mx) {
                mx = nums[i] ;
                mxIndex = i ;
            }
        }
        TreeNode* left = construct(nums, start, mxIndex -1) ;
        TreeNode* right = construct(nums, mxIndex + 1, end) ;
        TreeNode* node = new TreeNode(mx) ;
        node->left = left ;
        node->right = right;
        return node ;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        int start = 0 ;
        int end = n-1 ;
        return construct(nums, 0, n-1) ;
    }
};
