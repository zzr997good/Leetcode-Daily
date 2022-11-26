/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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
    int maxSumBST(TreeNode* root) {
        traversal(root);
        return res;
    }
private:
    struct tree_info{
        bool is_binary;
        int min;
        int max;
        int sum;
    };

    int res=0;

    tree_info traversal(TreeNode* root){
        tree_info me;
        if(root==nullptr){
            me.is_binary=true;
            me.min=INT_MAX;
            me.max=INT_MIN;
            me.sum=0;
            return me;
        }
        tree_info left=traversal(root->left);
        tree_info right=traversal(root->right);
        if(left.is_binary&&right.is_binary&&left.max<root->val&&right.min>root->val){
            me.is_binary=true;
            me.min=min(left.min,root->val);
            me.max=max(right.max,root->val);
            me.sum=left.sum+right.sum+root->val;
            res=max(res,me.sum);
        }
        else{
            me.is_binary=false;
        }
        return me;
    }
};
// @lc code=end

