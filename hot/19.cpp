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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = head;
        for (int i =0; i < n; i++){
            second = second->next;
        }
        while (second != nullptr){
            first=first->next;
            second=second->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }


    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        // 这个无法处理当元素只有一个的情况
        // ListNode* dummy = new ListNode(0, head);
        // ListNode* first = dummy;
        ListNode* first = head;
        ListNode* second = head;
        for (int i =0; i < n+1; i++){
            second = second->next;
        }
        while (second != nullptr){
            first=first->next;
            second=second->next;
        }
        first->next = first->next->next;
        if(first->next == nullptr){return nullptr;}
        return head;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    ListNode * list0 = new ListNode(0);
    ListNode * list1 = new ListNode(1);

    vec2list({1,2,3,4},list0);
    vec2list({2},list1);
    print_list(list0);
    print_list(list1);
    print_list(entity.removeNthFromEnd(list0,4));
    print_list(entity.removeNthFromEnd2(list1,1));

    return 0;
}
