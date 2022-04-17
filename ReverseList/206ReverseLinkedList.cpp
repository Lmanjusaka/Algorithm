//
// Created by liuchen on 2022/4/17.
//
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* pre = new ListNode(-1, head);
        ListNode* p = head;
        while(p->next){
            ListNode* post = p->next;
            p->next = post->next;
            post->next = pre->next;
            pre->next = post;
        }
        return pre->next;
    }
};
