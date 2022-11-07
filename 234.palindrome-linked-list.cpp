/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        // //way1: stored as string O(n)+O(n)
        // string val="";
        // ListNode* cur=head;
        // while(cur!=nullptr){
        //     val+=to_string(cur->val);
        //     cur=cur->next;
        // }
        // string temp=val;
        // reverse(val.begin(),val.end());
        // return temp==val;

        //way2: Reverse the second half linked list
        ListNode *fast=head, *slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* prev=nullptr, *cur=slow;
        while(cur!=nullptr){
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        slow=head,fast=prev;
        while(slow!=fast){
            if(slow->val!=fast->val) return false;
            if(slow->next==fast&&fast->next==nullptr) break;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};
// @lc code=end

