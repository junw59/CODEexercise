#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void vec2list(vector<int> data, ListNode * p, ListNode * last = nullptr){
    for (auto i : data){
        ListNode * l = new ListNode (i);
        p->next = l;
        p = l;
    }
    p->next = last;
}

void print_list(ListNode * p){
    ListNode * temp = p;
    while (temp != nullptr){
        cout << temp->val << "  ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
public:
    pair<ListNode*,ListNode*> reverse(ListNode* head, ListNode* tail){
        ListNode* prev=tail->next;
        ListNode* curr=head;
        while ( prev != tail){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {tail,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* tail = hair;
        for ( int i = 0; i < k; i ++){
            tail = tail->next;
            if(tail == nullptr){
                return hair->next;
            }
        }
        // 把tail后面的节点记下
        ListNode* next=tail->next;
        tie(head,tail) = reverse(head,tail);
        hair->next = head;
        tail->next = reverseKGroup(next , k);
        return hair->next;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    ListNode * list0 = new ListNode(0);
    ListNode * list1 = new ListNode(1);

    vec2list({1,2,3,4,5,6},list0);
    vec2list({2,4,6,8,10},list1);
    print_list(list0);
    print_list(list1);
    print_list(entity.reverseKGroup(list0,3));
    print_list(entity.reverseKGroup(list1,2));

    return 0;
}
