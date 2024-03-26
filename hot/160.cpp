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
    ListNode(int x) : val(x), next(NULL) {}
};

void vec2list(vector<int> data, ListNode * p, ListNode * last = nullptr){
    for (auto i : data){
        // p->val = i;
        // ListNode * l = new ListNode (i);
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode * temp =headA;
        while (temp != nullptr){
            visited.insert(temp);
            temp=temp->next;
        }
        temp = headB;
        while (temp != nullptr){
            if (visited.count(temp)){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr){
            return nullptr;
        }
        ListNode * pa =headA;
        ListNode * pb =headB;
        while( pa != pb){
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
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
    vec2list({5,6},list2,list0);
    print_list(list0);
    print_list(list1);
    print_list(list2);
    ListNode * results;
    results=entity.getIntersectionNode2(list1,list2);
    print_list(results);
    // cout << results << endl;

    return 0;
}
