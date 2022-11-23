/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     if(root==nullptr) return {};
    //     postorderTraversal(root->left);
    //     postorderTraversal(root->right);
    //     res.push_back(root->val);
    //     return res;
    // }

    // //Iterative:using my stack O(N)+O(N)
    // vector<int> postorderTraversal(TreeNode* root) {
    //     if(root==nullptr)  return {};
    //     stack<pair<TreeNode*,int>> stk;
    //     stk.push({root,0});
    //     vector<int> res;
    //     while(!stk.empty()){
    //         auto cur=stk.top();
    //         stk.pop();
    //         if(cur.second==0){
    //             stk.push({cur.first,1});
    //             if(cur.first->right) stk.push({cur.first->right,0});
    //             if(cur.first->left) stk.push({cur.first->left,0});
    //         }
    //         else{
    //             res.push_back(cur.first->val);
    //         }
    //     }
    //     return res;         
    // }
    
    //Iterative:using morris traversal no stack O(N)+O(1)
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        TreeNode* dummy=new TreeNode(-1);
        dummy->left=root;
        vector<int> res;
        TreeNode* cur=dummy;
        TreeNode* prev=nullptr;
        while(cur!=nullptr){
            if(cur->left==nullptr) {
                prev=cur;
                cur=cur->right;
            }
            else{
                TreeNode* pred=cur->left;
                while(pred->right!=nullptr&&pred->right!=cur){
                    pred=pred->right;
                }
                if(pred->right==nullptr){
                    pred->right=cur;
                    prev=cur;
                    cur=cur->left;
                }
                else{
                    addRightMost(cur->left,prev,res);
                    pred->right=nullptr;
                    prev=cur;
                    cur=cur->right;
                }
            }
        }
        return res;
    }

    void addRightMost(TreeNode* from, TreeNode* to, vector<int>& res){
        reversePath(from,to);
        TreeNode* cur=to;
        while(1){
            res.push_back(cur->val);
            if(cur==from) break;
            cur=cur->right;
        }
        reversePath(to, from);
    }

    void reversePath(TreeNode* from,TreeNode* to){
        if(from==to)   return;
        TreeNode* prev=from;
        TreeNode* cur=from->right;
        TreeNode* next=nullptr;
        while(1){
            next=cur->right;
            cur->right=prev;
            prev=cur;
            cur=next;
            if(prev==to) break;
        }
        return;
    }
};
// @lc code=end

