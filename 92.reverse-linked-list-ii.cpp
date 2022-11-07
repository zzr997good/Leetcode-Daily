/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        if(left!=1) {
            head->next=reverseBetween(head->next,left-1,right-1);
            return head;
        }
        //反转从头开始的right个节点
        else{
            // //Iterative way
            // ListNode *prev=nullptr, *cur=head;
            // int count=1;
            // while(count<=right){
            //     ListNode* temp=cur->next;
            //     cur->next=prev;
            //     prev=cur;
            //     cur=temp;
            //     count++;
            // }
            // head->next=cur;
            // return prev;

            // Recursive way
            ListNode* newhead=reverseBetween(head->next,left,right-1);
            ListNode* temp=head->next->next;
            head->next->next=head;
            head->next=temp;
            return newhead;
        }
    }
};
// @lc code=end

