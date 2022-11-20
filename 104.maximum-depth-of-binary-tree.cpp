/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        //Recursive+divide_and_conquer
        if(root==nullptr) return 0;
        int left_maxDepth=maxDepth(root->left);
        int right_maxDepth=maxDepth(root->right);
        return 1+max(left_maxDepth,right_maxDepth);
    }

    //Iterative: You can use DFS or BFS
};
// @lc code=end

