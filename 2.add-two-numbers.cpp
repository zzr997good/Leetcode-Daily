/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        int carry=0;
        int val=0;
        int x=0;
        int y=0;
        while(l1!=nullptr||l2!=nullptr){
            x=l1==nullptr?0:l1->val;
            y=l2==nullptr?0:l2->val;
            int sum=x+y+carry;
            carry=sum/10;
            val=sum%10;
            cur->next=new ListNode(val);
            cur=cur->next;
            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
        }
        if(carry!=0) cur->next=new ListNode(carry);
        return dummy->next;
    }
};
// @lc code=end

