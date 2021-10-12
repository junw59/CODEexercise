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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) return reverseN(head, right);

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }

    ListNode* successor = nullptr;
    ListNode* reverseN(ListNode* head, int n){
        if (n == 1){
            successor = head->next;
            return head;
        }

        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }
};

class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if ( left == right) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre;
        ListNode* cur;
        ListNode* nxt;
        ListNode* start;
        ListNode* end;
        start = dummy;
        for (int i = 0; i < left - 1; i++){
            start = start->next;
        }
        cur = start->next;
        end = cur;
        for (int i = left; i < right + 1; i++){
            end = end->next;
        }

        nxt = cur;
        pre = end;
        while (cur != end){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        start->next = pre;
        return dummy->next;
    }
};

int main(){
    // [1,2,3,4,5] 2 4
    Solution entity;
    Solution2 entity2;
    vector<int> data = {1,2,3,4,5};
    ListNode* p1 = new ListNode(-1);
    vectolist(data, p1);

    ListNode* p = entity.reverseBetween(p1->next, 2, 4);
    while (p != nullptr)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    vectolist(data, p1);
    ListNode* p2 = entity2.reverseBetween(p1->next, 2, 4);
    while (p2 != nullptr)
    {
        cout << p2->val << "\t";
        p2 = p2->next;
    }
    
}