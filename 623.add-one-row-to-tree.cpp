/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return traversal(root,val,depth,1);
    }
private:
    TreeNode* traversal(TreeNode* root, int val, int depth, bool is_left){
        if(depth==1){
            TreeNode* new_root=new TreeNode(val);
            if(is_left) new_root->left=root;
            else new_root->right=root;
            return new_root;
        }
        if(root==nullptr) return nullptr;
        root->left=traversal(root->left,val,depth-1,1);
        root->right=traversal(root->right,val,depth-1,0);
        return root;
    }
};
// @lc code=end

