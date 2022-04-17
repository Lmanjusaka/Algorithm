//
// Created by liuchen on 2022/4/16.
//
#include "unordered_set"
#include <iostream>
#include "algorithm"
#include "set"
using namespace std;

set<int> a ;
struct ListNode{
    int val;
    ListNode* next;
};
int main(){
//    a.emplace(3);
//    a.emplace(9);
//    a.emplace(11);
//    a.emplace(8);
//    a.emplace(7);
////    a.erase(11);
////    for (auto it = a.begin(); it != a.end(); ++it) {
////        cout<<*it<<endl;
////    }
////    sort(a.begin(), a.end());
//    set<int>::iterator it;
//    it = a.lower_bound(12);
//    cout<<(it==a.end())<<endl;
    ListNode* pre = new ListNode();
    pre->val = 9;
    pre->next = nullptr;
    ListNode* post = new ListNode();
    post->val = 11;
    post->next = nullptr;
    ListNode* head = new ListNode();
    head->val = 10;
    head->next = post;
    ListNode* p = head;
    cout<<head->next->val;
    head->next = pre;
    head->val = 22;
    cout<<p->val;
    cout<<p->next->val;


}
