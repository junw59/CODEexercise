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

void vectolist_ring(vector<int> &data, ListNode * p, int pos){
    for (auto i : data){
        ListNode * l = new ListNode(i);
        p->next = l;
        p = p->next;
    }
    ListNode * dummy = new ListNode(-1);
    ListNode * l = dummy;
    for (int i = 0; i < pos; i++){
        l->next = l;
    }
    if (dummy->next!=nullptr)
        p->next = dummy->next;
}

class Solution {
public:
    bool middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if ( slow == fast) return true;
        }
        return false;
    }
};

class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if ( slow == fast){
                slow = head;
                while (fast->next != nullptr){
                    if ( slow == fast) return slow;
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
        return nullptr;
    }
};

int main(){
    // [3,2,0,-4] 1
    ListNode* data = new ListNode(-1);
    vector<int> init = {3,2,0,-4};
    vectolist_ring(init, data, 2);
    Solution entity;
    bool p = entity.middleNode(data->next);
    cout << p << endl;

    Solution2 entity2;
    ListNode* p2 = entity2.detectCycle(data->next);
    data = data->next;
    while (data->next != p2)
    {
        cout << data->val << "\t";
        data = data->next;
    }
    
}