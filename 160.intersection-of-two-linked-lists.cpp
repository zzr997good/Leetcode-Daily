/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // //方法1:用一个unordered_set记录list1中所有节点地址，然后遍历list2，第一个出现的重复地址就是交点节点地址
        // unordered_set<ListNode*> record;
        // ListNode *cur=headA;
        // while(cur!=nullptr) {
        //     record.insert(cur);
        //     cur=cur->next;
        // }
        // cur=headB;
        // while(cur!=nullptr){
        //     if(record.count(cur)) return cur;
        //     cur=cur->next;
        // }
        // return nullptr;

        // //方法2:先求出两个链表各自长度，然后让长的链表先走几步直到二者相同，然后开始一起走，当两个指针相同的时候，说明有交点。
        // int lenA=0,lenB=0;
        // ListNode *curA=headA, *curB=headB;
        // while(curA!=nullptr){
        //     lenA++;
        //     curA=curA->next;
        // }
        // while(curB!=nullptr){
        //     lenB++;
        //     curB=curB->next;
        // }
        // curA=headA;
        // curB=headB;
        // while(lenB>lenA) {
        //     curB=curB->next;
        //     lenB--;
        // }
        // while(lenA>lenB){
        //     curA=curA->next;
        //     lenA--;
        // }
        // while(lenB!=0&&lenA!=0){
        //     if(curB==curA) return curB;
        //     curB=curB->next;
        //     curA=curA->next;
        //     lenB--;
        //     lenA--;
        // }
        // return nullptr;
        
        //方法3让两个指针ptrA和ptrB同时从头开始遍历链表listA和listB，当ptrA遍历到listA尾时让它从头开始遍历listB，当ptrA遍历到listA尾时让它从头开始遍历listA，当两个指针相等时就指向公共节点或者nullptr
        ListNode* ptrA=headA, *ptrB=headB;
        while(ptrA!=ptrB){
            if(ptrA!=nullptr) ptrA=ptrA->next;
            else ptrA=headB;
            if(ptrB!=nullptr) ptrB=ptrB->next;
            else ptrB=headA;
        }
        //If two lists have the intersection node, return that node
        //If two lists have no intersection, return nullptr
        return ptrA;
    }
};
// @lc code=end

