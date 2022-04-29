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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || head->next == NULL)
            return head;
        int index = 1;
        ListNode* oddListHead = new ListNode(0);
        ListNode* evenListHead = new ListNode(0);
        ListNode* oddList = oddListHead;
        ListNode* evenList = evenListHead;
        while (head != NULL){
            if (index % 2 == 1){
                evenList->next = head;
                evenList = evenList->next;
            }
            else{
                oddList->next = head;
                oddList = oddList->next;
            }
            head = head->next;
            index++;
        }
        if (index / 2 == 0){
            evenList->next = NULL;
            oddList->next = evenListHead->next;
            return oddListHead->next;
        } else{
            oddList->next = NULL;
            evenList->next = oddListHead->next;
            return evenListHead->next;
        }

    }
};
int main(){
//    int arr[7] = {2, 1, 3, 5, 6, 4, 7};
    int arr[5] = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr, size(arr));
    Solution* res = new Solution();
    printList(head);
    res->oddEvenList(head);
    printList(head);

}