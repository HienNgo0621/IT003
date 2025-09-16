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
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string>ans;
       if(root==NULL)return ans;
       traversal(root,"",ans);
       return ans;
    }

    void traversal(TreeNode* root,string path,vector<string>&ans)
    {
        if(root==NULL)return;

        if(path.size()==0)
        {
            path+=to_string(root->val);
        }
        else{
            path+="->"+to_string(root->val);
        }

         if(!root->left && !root->right)
        {
           ans.push_back(path);
           return;
        }


        traversal(root->left,path,ans);
        traversal(root->right,path,ans);
    }
};
