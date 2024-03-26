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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr){
            return list2;
        } else if (list2 == nullptr){
            return list1;
        } else if (list1->val < list2->val){
            list1 -> next = mergeTwoLists(list1->next, list2);
            return list1;
        } else{
            list2 -> next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        ListNode * pre_head= new ListNode(-1);
        ListNode * pre = pre_head;
        while ( list1 != nullptr && list2 != nullptr)
        {
            if ( list1->val < list2->val){
                pre -> next = list1;
                list1= list1 -> next ;
            }else{
                pre->next = list2;
                list2= list2 -> next ;
            }
            pre = pre->next;
        }
        pre ->next = list1 == nullptr ? list2: list1;
        return pre_head->next;
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    ListNode * list0 = new ListNode(0);
    ListNode * list1 = new ListNode(1);

    vec2list({1,2,3,4},list0);
    vec2list({2,4},list1);
    print_list(list0);
    print_list(list1);
    print_list(entity.mergeTwoLists2(list0,list1));

    return 0;
}
