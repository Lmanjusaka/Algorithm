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
# include "iostream"
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
//        ListNode* pre = new ListNode(-1, head);
//        ListNode* p = head;
//        while(p->next){
//            ListNode* post = p->next;
//            p->next = post->next;
//            post->next = pre->next;
//            pre->next = post;
//        }
//        ListNode* retNode = pre->next;
//        delete pre;
//        return retNode;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* p = head;
        while (p){
            ListNode* next = p->next;
            p->next = pre->next;
            pre->next = p;
            p = next;
        }
        head->next = NULL;
        ListNode* retNode = pre->next;
        delete pre;
        return retNode;
    }
};
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr, 5);
    Solution* res = new Solution();
    printList(head);
    ListNode* head1 = res->reverseList(head);
    printList(head1);

}