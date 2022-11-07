/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Check there are at least k nodes
        int count=k;
        ListNode* cur=head;
        while(count>0){
            if(cur==nullptr) return head;
            else {
                cur=cur->next;
                count--;
            }
        }
        //Pass check:Reverve the back n-k nodes first
        ListNode *reversedhead=reverseKGroup(cur, k);
        //Reverse the first k nodes
        return reversek(head,k,reversedhead);
    }
private:
    ListNode* reversek(ListNode* head,int k, ListNode* next){
        if(k==1) {
            head->next=next;
            return head;
        }
        else{
            ListNode* newhead=reversek(head->next,k-1,next);
            head->next->next=head;
            head->next=next;
            return newhead;
        }
    }
};
// @lc code=end

