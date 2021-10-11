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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main(){
    // [1,2,3,4,5] 2
    ListNode* data = new ListNode(-1);
    vector<int> init = {1,2,3,4,5,6};
    vectolist(init, data);
    Solution entity;
    ListNode* p = entity.middleNode(data->next);
    while (p != nullptr)
    {
        cout << p->val << "\t";
        p = p->next;
    }
}