#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list->
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1); // 复制一份初始的方便找开头
        ListNode* p = dummy;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while ( p1 != nullptr && p2 != nullptr){
            if (p1->val > p2->val){
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }

            p = p->next;
        }

        if (p1 != nullptr){
            p->next = p1;
        }

        if (p2 != nullptr){
            p->next = p2;
        }

        return dummy->next;
    }
};

void vectolist(vector<int> &data, ListNode * p){
    for (auto i : data){
        ListNode * l = new ListNode(i);
        p->next = l;
        p = p->next;
    }
}

int main(){
    Solution entity;
    vector<int> data1 = {1,2,4};
    ListNode* p1 = new ListNode(-1);
    vectolist(data1,p1);
    vector<int> data2 = {1,3,4};
    ListNode* p2 = new ListNode(-1);
    vectolist(data2,p2);

    ListNode* dummy = entity.mergeTwoLists(p1->next, p2->next);
    ListNode* p = dummy;
    while (p!=nullptr){
        cout << p->val << "\t";
        p = p->next;
    }
    // cout << 
}