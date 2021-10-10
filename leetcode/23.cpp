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
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() < 1) return nullptr;

        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        priority_queue<Status> q;

        for (auto li: lists){
            if ( li!= nullptr){
                q.push({li->val, li});
            }
        }

        while (!q.empty()){
            ListNode *cur = q.top().ptr;
            q.pop();

            p->next = cur;
            if (cur->next != nullptr) q.push({cur->next->val,cur->next});

            p = p->next;
        }

        return dummy->next;
    }
};


void vectolist(vector<int> &data, ListNode * p){
    for (auto i : data){
        ListNode * l = new ListNode(i);
        p->next = l;
        p = p->next;
    }
}

int main(){
    Solution entity;
    // [[1,4,5],[1,3,4],[2,6]]
    vector<vector<int>> data = {{1,4,5},{1,3,4},{2,6}};
    vector<ListNode*> lists;

    for (auto i: data){
        ListNode* p1 = new ListNode(-1);
        vectolist(i,p1);
        lists.push_back(p1->next);
    }

    ListNode* dummy = entity.mergeKLists(lists);
    ListNode* p = dummy;
    while (p!=nullptr){
        cout << p->val << "\t";
        p = p->next;
    }
    // cout << 
}