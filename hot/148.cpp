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
    ListNode* sortList(ListNode* head) {
        return sortList(head,nullptr);
    }
    ListNode* sortList(ListNode* head,ListNode* tail) {
        if (head==nullptr){
            return head;
        }
        if (head->next==tail){
            head->next =nullptr;
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while ( fast != tail){
            slow=slow->next;
            fast=fast->next;
            if ( fast != tail){
                fast=fast->next;
            }
        }
        ListNode* mid=slow;
        return mergeList(sortList(head,mid),sortList(mid,tail));
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2){
        if (l1 == nullptr){
            return l2;
        } else if ( l2 == nullptr){
            return l1;
        } else if ( l1->val< l2->val){
            l1->next = mergeList(l1->next,l2);
            return l1;
        } else{
            l2->next = mergeList(l2->next,l1);
            return l2;
        }
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    ListNode * list0 = new ListNode(0);
    ListNode * list1 = new ListNode(1);

    vec2list({1,2,9,3,4},list0);
    vec2list({1,5},list1);
    print_list(list0);
    print_list(list1);
    print_list(entity.mergeList(list0,list1));
    print_list(entity.sortList(list0));

    return 0;
}
