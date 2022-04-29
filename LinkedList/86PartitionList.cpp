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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = new ListNode(0);
        ListNode* largeHead = new ListNode(0);
        ListNode* small = smallHead;
        ListNode* large = largeHead;
        while(head != NULL){
            if (head->val < x) {
                small->next = head;
                small = small->next;
            }
            else{
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = NULL;
        small->next = largeHead->next;
        return smallHead->next;
    }
};
int main(){
    int arr[6] = {1, 4, 3, 2, 5, 2};
    ListNode* head = createList(arr, size(arr));
    Solution* res = new Solution();
    printList(head);
    res->partition(head, 3);
    printList(head);

}