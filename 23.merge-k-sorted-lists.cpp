/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp{
        bool operator()(ListNode* & Node1,ListNode* &Node2){
            return Node1->val>Node2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> smallheap;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]!=nullptr)  smallheap.push(lists[i]);
        }
        ListNode* dummy=new ListNode(-1); 
        ListNode* cur=dummy;
        while(!smallheap.empty()){
            cur->next=smallheap.top();
            cur=cur->next;
            smallheap.pop();
            if(cur->next!=nullptr) smallheap.push(cur->next);
        }
        return dummy->next;

    }
};
// @lc code=end

