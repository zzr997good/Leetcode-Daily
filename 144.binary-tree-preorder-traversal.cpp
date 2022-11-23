/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // //Recursive:using system stack O(N)+O(N)
    // vector<int> res;
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root==nullptr) return {};
    //     res.push_back(root->val);
    //     preorderTraversal(root->left);
    //     preorderTraversal(root->right);
    //     return res;
    // }

    //Iterative:using my stack O(N)+O(N)
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root==nullptr)  return {};
    //     stack<TreeNode*>   stk;
    //     stk.push(root);
    //     vector<int> res;
    //     while(!stk.empty()){
    //         TreeNode* cur=stk.top();
    //         stk.pop();
    //         res.push_back(cur->val);
    //         if(cur->right) stk.push(cur->right);
    //         if(cur->left)   stk.push(cur->left);
    //     }
    //     return res;         
    // }
    
    //Iterative:using morris traversal no stack O(N)+O(1)
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        TreeNode* cur=root;
        while(cur!=nullptr){
            if(cur->left==nullptr) {
                res.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* pred=cur->left;
                while(pred->right!=nullptr&&pred->right!=cur){
                    pred=pred->right;
                }
                if(pred->right==nullptr){
                    res.push_back(cur->val);
                    pred->right=cur;
                    cur=cur->left;
                }
                else{
                    pred->right=nullptr;
                    cur=cur->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end

