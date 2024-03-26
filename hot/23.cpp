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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ans=nullptr;
        int n = lists.size();
        for (int i =0; i < n;i++){
            ans = mergeList(ans,lists[i]);
        }
        return ans;
    }


    ListNode* mergeList(ListNode* l1, ListNode* l2){
        if (l1 == nullptr){
            return l2;
        } else if ( l2 == nullptr){
            return l1;
        } else if ( l1->val< l2->val){
            // cout << l1->val << " ";
            l1->next = mergeList(l1->next,l2);
            return l1;
        } else{
            // cout << l2->val << " ";
            l2->next = mergeList(l2->next,l1);
            return l2;
        }
    }


    ListNode* merge_lr(vector<ListNode*>& lists, int l, int r) {
        if (l==r){
            return lists[l];
        }
        if ( l>r){
            return nullptr;
        }
        int mid = (l+r)/2;
        return mergeList(merge_lr(lists,l,mid),merge_lr(lists,mid+1,r));
    }


    ListNode* mergeKLists_fz(vector<ListNode*>& lists) {
        return merge_lr(lists,0,lists.size()-1);
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    ListNode * list0 = new ListNode(0);
    ListNode * list1 = new ListNode(1);
    ListNode * list2 = new ListNode(2);

    vec2list({7,8,9},list0);
    vec2list({3,5},list1);
    vec2list({4,6},list2);
    print_list(list0);
    print_list(list1);
    print_list(list2);
    // print_list(entity.mergeList(list0,list1));
    vector<ListNode*> three_list = {list0,list1,list2};
    // print_list(entity.mergeKLists(three_list));
    print_list(entity.mergeKLists_fz(three_list));

    return 0;
}
