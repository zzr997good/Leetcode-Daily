/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
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
    int rob(TreeNode* root) {
        return dp(root);
    }
private:
    unordered_map<TreeNode*,int> memo;
    int dp(TreeNode* root){
        if(root==nullptr) return 0;
        if(memo.count(root)) return memo[root];
        int utake=dp(root->left)+dp(root->right);
        int take=root->val;
        if(root->left) take=take+dp(root->left->left)+dp(root->left->right);
        if(root->right) take=take+dp(root->right->left)+dp(root->right->right);
        memo[root]=max(utake,take);
        return memo[root];
    }
};
// @lc code=end

