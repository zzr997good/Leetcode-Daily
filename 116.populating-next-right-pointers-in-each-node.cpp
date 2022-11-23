/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start

// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };

class Solution {
public:
    Node* connect(Node* root) {
        // //Recursive 
        // if(root==nullptr) return root;
        // root->left=connect(root->left);
        // root->right=connect(root->right);
        // Node* lr=root->left;
        // Node* rl=root->right;
        // while(lr){
        //     lr->next=rl;
        //     lr=lr->right;
        //     rl=rl->left;
        // }
        // return root;
        
        //Iterative
        if(root==nullptr) return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int sz=que.size();
            for(int i=0;i<sz;i++){
                Node* cur=que.front();
                que.pop();
                if(i!=sz-1) cur->next=que.front();
                if(cur->left) que.push(cur->left);
                if(cur->right)  que.push(cur->right);
            }
        }
        return root;
    }
};
// @lc code=end

