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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left >= right)
            return head;

        ListNode* dummy_node = new ListNode(-1, head);
        ListNode* pre = dummy_node;
        for(int i = 0; i < left - 1; i++){
            pre = pre->next;
        }
        ListNode* p = pre->next;
        for(int i = 0; i < right - left; i++){
            ListNode* post = p->next;
            p->next = post->next;
            post->next = pre->next;
            pre->next = post;
        }
        return dummy_node->next;
    }
};