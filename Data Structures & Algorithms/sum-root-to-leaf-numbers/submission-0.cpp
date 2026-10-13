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
    void helper(TreeNode*root,string&res,int &ans){
        if(!root) return;
        res+=to_string(root->val);
        if(!root->left && !root->right){
            ans+=stoi(res);
            res.pop_back();
            return;
        }
        helper(root->left,res,ans);
        helper(root->right,res,ans);
        res.pop_back();
    }
    int sumNumbers(TreeNode* root) {
       string res = "";
       int ans = 0;
       helper(root,res,ans);
       return ans; 
    }
};