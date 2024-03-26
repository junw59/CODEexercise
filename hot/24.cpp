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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode * temp;
        temp=head->next;
        head->next=swapPairs(temp->next);;
        temp->next=(head);
        return temp;
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
    print_list(entity.swapPairs(list0));
    print_list(entity.swapPairs(list1));

    return 0;
}
