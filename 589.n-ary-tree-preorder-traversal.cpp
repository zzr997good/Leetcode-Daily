/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// class Solution {
// public:
//     //Recursive way
//     vector<int> preorder(Node* root) {
//         if(root==nullptr) return {};
//         res.push_back(root->val);
//         for(auto child:root->children)
//             preorder(child);
//         return res;
//     }

// private:
//     vector<int> res;
// };

class Solution {
public:
    //Iterative way
    vector<int> preorder(Node* root) {
        if(root==nullptr) return {};
        stack<Node*> stk;
        vector<int> res;
        stk.push(root);
        while(!stk.empty()){
            Node* cur=stk.top();
            stk.pop();
            res.push_back(cur->val);
            for(int i=cur->children.size()-1;i>=0;i--){
                stk.push(cur->children[i]);
            }
        }
        return res;
    }

};
// @lc code=end

