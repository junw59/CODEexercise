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
    bool hasCycle(ListNode *head) {
        unordered_set <ListNode*> mp;
        while (head != nullptr){
            if ( mp.count(head)){
                return true;
            }
            mp.insert(head);
            head = head->next;
        }
        return false;
    }

    bool hasCycle2(ListNode *head) {
        if (head == nullptr||head->next == nullptr ){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while ( slow != fast){
            if (fast->next == nullptr ||fast->next->next == nullptr){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
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
    cout << entity.hasCycle2(list0) << endl;
    ListNode * temp = list0;
    int i = 0;
    while ( temp != nullptr){
        if (i>10) break;
        cout << temp->val << "  ";
        temp = temp->next;
        i++;
    }
    cout << endl;

    return 0;
}
