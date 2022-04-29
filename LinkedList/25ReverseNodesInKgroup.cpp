//
// Created by liuchen on 2022/4/26.
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
# include "tuple"
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
pair<ListNode*, ListNode*> ReverseList(ListNode* head, ListNode* tail){
    ListNode* pre = tail->next;
    ListNode* p = head;
    while (pre != tail){
        ListNode* next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }
    return {tail, head};
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* pre = dummyNode;
        while (head){
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail){
                    ListNode* retNode = dummyNode->next;
                    delete dummyNode;
                    return retNode;
                }
            }
//            ListNode* next = tail->next;
            tie(head, tail) = ReverseList(head, tail);
            pre->next = head;
//            tail->next = next;
            pre = tail;
            head = tail->next;
        }
        ListNode* retNode = dummyNode->next;
        delete dummyNode;
        return retNode;
    }
};
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr, 5);
    Solution* res = new Solution();
    printList(head);
    head = res->reverseKGroup(head, 2);
    printList(head);

}