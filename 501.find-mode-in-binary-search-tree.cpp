/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> findMode(TreeNode* root) {
        //Inorder traversal is a non-decreasing sequences, just like looking for the mode in the vector
        traversal(root);
        return res;
    }

private:
    int last_num=-100001;
    vector<int> res;
    int max_freq=0;
    int cur_freq=0;
    void traversal(TreeNode* root){
        if(root==nullptr) return;
        //Get the info about the max_freq and last_num and cur_freq of nums before root->val
        traversal(root->left);
        if(last_num==root->val)  cur_freq++;
        else cur_freq=1;
        if(cur_freq==max_freq) res.push_back(root->val);
        if(cur_freq>max_freq) {
            max_freq=cur_freq;
            res.clear();
            res.push_back(root->val);
        }
        last_num=root->val;
        traversal(root->right);
    }
};
// @lc code=end

