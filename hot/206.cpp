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
        // p->val = i;
        // ListNode * l = new ListNode;
        // p->next = l;
        // p = l;

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
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = nullptr;
        ListNode * curr = head;
        while (curr != nullptr){
            ListNode * next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseList2(ListNode* head) {
        if (! head || ! head->next){
            return head;
        }
        ListNode * newHead = reverseList2( head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    ListNode * list0 = new ListNode(0);
    ListNode * list1 = new ListNode(1);
    ListNode * list2 = new ListNode(2);

    vec2list({1,8,4,5},list0);
    vec2list({2,4},list1,list0);
    print_list(list1);
    ListNode * results;
    results=entity.reverseList2(list1);
    print_list(results);
    cout << results << endl;

    return 0;
}
