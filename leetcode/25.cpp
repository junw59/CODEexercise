#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void vectolist(vector<int> &data, ListNode * p, ListNode* last = nullptr){
    for (auto i : data){
        ListNode * l = new ListNode(i);
        p->next = l;
        p = p->next;
    }
    p->next = last;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* a;
        ListNode* b;
        a = head; b = head;
        for ( int i = 0; i < k; i++){
            if (b == nullptr) return head;
            b = b->next;
        }

        ListNode* newhead = reverse(a, b);
        a->next = reverseKGroup(b, k);

        return newhead;
    }

    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode* pre;
        ListNode* cur;
        ListNode* nxt;
        pre = nullptr; cur = a; nxt = a;

        while (cur != b){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

int main(){
    // [1,2,3,4,5] 2
    Solution entity;
    vector<int> data = {1,2,3,4,5};
    ListNode* p1 = new ListNode(-1);
    vectolist(data, p1);

    ListNode* p = entity.reverseKGroup(p1->next, 2);
    while (p != nullptr)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    
}