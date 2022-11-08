/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
        int len=0;
        ListNode* prev=nullptr, *cur=head;
        while(cur!=nullptr){
            len++;
            prev=cur;
            cur=cur->next;
        }
        if(k%len==0) return head;
        prev->next=head;
        int step=len-k%len;
        cur=head,prev=nullptr;
        while(step>0){
            prev=cur;
            cur=cur->next;
            step--;
        }
        prev->next=nullptr;
        return cur;
    }
};
// @lc code=end

