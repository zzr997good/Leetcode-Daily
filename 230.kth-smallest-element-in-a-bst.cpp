/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return -1;
        //先到左边去找
        int left_res=kthSmallest(root->left, k);
        //左边找到了
        if(left_res!=-1) return left_res;
        //左边没找到，看看当前节点是不是
        rank++;
        //当前节点是
        if(rank==k) return root->val;
        //当前节点不是，到右边去找
        int right_res=kthSmallest(root->right, k);
        //右边找到了
        if(right_res!=-1) return right_res;
        //右边没找到
        return -1;

    }
private:
    int rank=0;
};
// @lc code=end

