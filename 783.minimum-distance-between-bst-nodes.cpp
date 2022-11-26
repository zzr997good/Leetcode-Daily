/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        if(root==nullptr) return -1;
        minDiffInBST(root->left);
        if(last_visited!=-1&&root->val-last_visited<min_diff)   min_diff=root->val-last_visited;
        last_visited=root->val;
        minDiffInBST(root->right);
        return min_diff;
    }
private:
    int last_visited=-1;
    int min_diff=100001;
};
// @lc code=end

