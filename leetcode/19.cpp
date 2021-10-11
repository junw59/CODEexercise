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

void vectolist(vector<int> &data, ListNode * p){
    for (auto i : data){
        ListNode * l = new ListNode(i);
        p->next = l;
        p = p->next;
    }
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* p1 = findFromEnd(dummy, n + 1);
        p1->next = p1->next->next;

        return dummy->next;
    }

    ListNode* findFromEnd(ListNode* head, int n){
        ListNode* p1 = head;
        for (int i = 0; i < n; i++) p1 = p1->next;
        ListNode* p2 = head;
        while (p1 != nullptr){
            p2 = p2->next;
            p1 = p1->next;
        }
        return p2;
    }
};

int main(){
    // [1,2,3,4,5] 2
    ListNode* data = new ListNode(-1);
    vector<int> init = {1,2,3,4,5};
    vectolist(init, data);
    Solution entity;
    ListNode* p = entity.removeNthFromEnd(data->next, 2);
    while (p != nullptr)
    {
        cout << p->val << "\t";
        p = p->next;
    }
}