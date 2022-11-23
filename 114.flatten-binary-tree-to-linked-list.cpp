/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         //Recursive Way: O(N)+O(N)
//         //不要被题目的preorder迷惑，这题必然是中序递归，他告诉你preorder只是告诉你在中序位置应该按什么顺序放置左枝结果和当前节点
//         if(root==nullptr) return;
//         if(!root->left) last=root;
//         else{
//             flatten(root->left);
//             last->right=root->right;
//             root->right=root->left;
//             root->left=nullptr;
//         }
//         flatten(last->right);
//     }
// private:
//     TreeNode* last;
// };

class Solution {
public:
    void flatten(TreeNode* root) {
        //Morris Traversal
        if(root==nullptr) return;
        TreeNode* cur=root;
        while(cur!=nullptr){
            if(cur->left==nullptr) cur=cur->right;
            else{
                //find its predecessor
                TreeNode* pred=cur->left;
                while(pred->right!=nullptr&&pred->right!=cur) pred=pred->right;
                //This is the first time visit cur,which means preorder
                if(pred->right==nullptr){
                    pred->right=cur;
                    cur=cur->left;
                }
                //This is the second time visit cur, through predecessor, which means inorder
                //It also means the left subtree is flattened, and the predecessor is the last node in left flattened subtree
                else{
                    pred->right=cur->right;
                    cur->right=cur->left;
                    cur->left=nullptr;
                    cur=cur->right;
                }
                
            }
        }
    }
};
// @lc code=end

