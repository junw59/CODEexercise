#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void vec2list(vector<int> data, Node * p, Node * last = nullptr){
    for (auto i : data){
        Node * l = new Node (i);
        p->next = l;
        p = l;
    }
    p->next = last;
}

void print_list(Node * p){
    Node * temp = p;
    while (temp != nullptr){
        cout << temp->val << "  ";
        temp = temp->next;
    }
    cout << endl;
}


class Solution {
public:
    unordered_map<Node*, Node*> node_mp;
    Node* copyRandomList(Node* head) {
        if (head == nullptr){
            return nullptr;
        }
        if ( node_mp.count(head) ==0){
            Node* new_head = new Node (head->val);
            node_mp[head] = new_head;
            new_head->next = copyRandomList(head->next);
            new_head->random = copyRandomList(head->random);
        }
        return node_mp[head];
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    Node * list0 = new Node(0);
    Node * list1 = new Node(1);

    vec2list({1,2,3,4,5,6},list0);
    vec2list({2,4,6,8,10},list1);
    print_list(list0);
    print_list(list1);
    print_list(entity.copyRandomList(list0));
    print_list(entity.copyRandomList(list1));

    return 0;
}
