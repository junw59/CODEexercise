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
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }
    
    bool traverse(ListNode* right){
        if (right == nullptr) return true;
        bool res = traverse(right->next);

        res = res && (right->val == left->val);
        left = left->next;
        return res;
    }
};

class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* left = head;
        ListNode* right = reverse(findmid(head));
        while (right != nullptr){
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    // 查找链表中点
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) slow = slow->next;
        return slow;
    }

    // 翻转链表
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head;
        while (cur != nullptr){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

int main(){
    // [1,2,2,1], [1,2]
    Solution entity;
    Solution2 entity2;
    // Solution2 entity2;
    vector<int> data = {1,2,3,2,1};
    ListNode* p1 = new ListNode(-1);
    vectolist(data, p1);

    cout << entity.isPalindrome(p1->next) << endl;
    cout << entity2.isPalindrome(p1->next) << endl;
}