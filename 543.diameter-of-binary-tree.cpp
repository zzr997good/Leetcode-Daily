/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        //For each root node, the diameter should be left_depth+right_depth
        getHeight(root);
        return max_len;
    }
private:
    int max_len=-1;

    //Caculate the depth of this tree
    int getHeight(TreeNode* root){
        if(root==nullptr) return -1;
        int left_height=getHeight(root->left);
        int right_height=getHeight(root->right);
        int my_diameter=left_height+1+right_height+1;
        max_len=max(max_len,my_diameter);
        return max(left_height,right_height)+1;
    }
};
// @lc code=end

