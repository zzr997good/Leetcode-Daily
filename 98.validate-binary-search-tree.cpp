/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

//Traverse way
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root)[0];
    }
private:
    vector<long long> helper(TreeNode* root){
        //{isValid,max_val,min_val}
        if(root==nullptr) return {1,LLONG_MIN,LLONG_MAX};
        vector<long long> left=helper(root->left);
        vector<long long> right=helper(root->right);
        if(left[0]==0) return {0,0,0};
        if(right[0]==0) return {0,0,0};
        if(left[1]>=root->val||right[2]<=root->val) return {0,0,0};
        int mx=(root->val>right[1]?root->val:right[1]);
        int mn=(root->val<left[2]?root->val:left[2]);
        return {1,mx,mn};
    }
};
// @lc code=end

