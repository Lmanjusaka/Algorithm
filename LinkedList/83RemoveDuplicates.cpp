//
// Created by liuchen on 2022/4/20.
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
ListNode* createList(int arr[], int n){
    if(n == 0)
        return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < n; i++){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}
void printList(ListNode* head){
    ListNode* temp = head;
    while (temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    return;
}
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *cur = head;
        while (cur->next != NULL) {
            ListNode *del_node = cur->next;
            if (cur->val == del_node->val) {
                cur->next = del_node->next;
                delete del_node;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
int main(){
    int arr[5] = {1, 1, 2};
    ListNode* head = createList(arr, 5);
    Solution* res = new Solution();
    printList(head);
    res->deleteDuplicates(head);
    printList(head);

}