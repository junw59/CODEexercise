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

void circle_list(ListNode * p, int n){
    int i = 0;
    ListNode * temp;
    ListNode * prev;
    while (p != nullptr){
        if (i==n){
            temp = p;
        }
        prev = p;
        p = p->next;
        i++;
    }
    prev ->next = temp;
}

class Solution {
public:
    ListNode * detectCycle(ListNode *head) {
        unordered_set <ListNode*> mp;
        while (head != nullptr){
            if ( mp.count(head)){
                return head;
            }
            mp.insert(head);
            head = head->next;
        }
        return nullptr;
    }

    ListNode * detectCycle2(ListNode *head) {
        if (head == nullptr||head->next == nullptr ){
            return nullptr;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        do{
            if (fast->next == nullptr ||fast->next->next == nullptr){
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    ListNode * list0 = new ListNode(0);
    ListNode * list1 = new ListNode(1);

    vec2list({1,2,3,4},list0);
    vec2list({2,4},list1,list0);
    print_list(list0);
    print_list(list1);
    circle_list(list0,2);
    cout << entity.detectCycle2(list0) << endl;

    return 0;
}
