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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2){
            if (p1 != nullptr) p1 = p1->next;
            else p1 = headB;
            if (p2 != nullptr) p2 = p2->next;
            else p2 = headA;
        }
        return p1;
    }
};

int main(){
    // 8
    // [4,1,8,4,5]
    // [5,6,1,8,4,5]
    // 2
    // 3
    ListNode* data0 = new ListNode(-1);
    ListNode* data1 = new ListNode(-1);
    ListNode* data2 = new ListNode(-1);
    vector<int> init0 = {1,8,4,5};
    vector<int> init1 = {5,6,0,1};
    vector<int> init2 = {4,1};
    vectolist(init0, data0);
    vectolist(init1, data1, data0->next);
    vectolist(init2, data2, data0->next);

    Solution entity;
    ListNode* p = entity.getIntersectionNode(data1->next, data2->next);
    while (p != nullptr){
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    p = data1->next;
    while (p != nullptr){
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    p = data2->next;
    while (p != nullptr){
        cout << p->val << "\t";
        p = p->next;
    }
}