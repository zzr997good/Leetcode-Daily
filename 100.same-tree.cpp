/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Recursive
        if(p==nullptr&&q!=nullptr)  return false;
        if(p!=nullptr&&q==nullptr)  return false;
        if(p==nullptr&&q==nullptr)  return true;
        return (p->val==q->val&&isSameTree(p->left, q->left)&&isSameTree(p->right,q->right));
};
// @lc code=end

