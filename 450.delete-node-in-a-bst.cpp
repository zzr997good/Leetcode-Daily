/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(key<root->val) root->left=deleteNode(root->left,key);
        else if(key>root->val) root->right=deleteNode(root->right,key);
        else{
            if(root->left==nullptr) {
                root=root->right;
            }
            else if(root->right==nullptr){
                root=root->left;
            }
            else{
                TreeNode* prev=root->left;
                while(prev->right) prev=prev->right;
                int root_num=prev->val;
                root->val=root_num;
                root->left=deleteNode(root->left,root_num);
            }
        }
        return root;
    }
};
// @lc code=end

