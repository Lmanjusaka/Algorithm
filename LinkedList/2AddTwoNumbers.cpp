//
// Created by liuchen on 2022/4/21.
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
# include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(int arr[], int n) {
    if (n == 0)
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < n; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode *head) {
    ListNode *temp = head;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l = l1;
        ListNode *l1_pre = NULL;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            l1->val = l1->val + l2->val + carry;
            if (l1->val >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            l1->val = l1->val % 10;
            l1_pre = l1;
            if (l1->next == NULL && l2->next == NULL && carry == 1) {
                ListNode *node = new ListNode(1);
                l1->next = node;
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            l1->val = l1->val + carry;
            if (l1->val >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            l1->val = l1->val % 10;
            if (l1->next == NULL && carry == 1) {
                ListNode *node = new ListNode(1);
                l1->next = node;
                carry = 0;
            }
            l1 = l1->next;
        }
        while (l2 != NULL) {
            l2->val = l2->val + carry;
            if (l2->val >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            l2->val = l2->val % 10;
            if (l2->next == NULL && carry == 1) {
                ListNode *node = new ListNode(1);
                l2->next = node;
                carry = 0;
            }
            l1_pre->next = l2;
            l1_pre = l1_pre->next;
            l2 = l2->next;
        }
        return l;
    }
};

int main() {
//    int arr1[7] = {9, 9, 9, 9, 9, 9, 9};
//    int arr2[4] = {9, 9 ,9, 9};
    int arr1[3] = {2, 4, 9};
    int arr2[4] = {5, 6, 4, 9};
    ListNode *head1 = createList(arr1, size(arr1));
    ListNode *head2 = createList(arr2, size(arr2));
    Solution *res = new Solution();
    printList(head1);
    printList(head2);
    ListNode *head = res->addTwoNumbers(head1, head2);
    printList(head);

}