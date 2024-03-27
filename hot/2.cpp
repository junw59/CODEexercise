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

ListNode * vec2list(vector<int> data){
    ListNode * p = new ListNode();
    ListNode * dummy=p;
    for (auto i : data){
        ListNode * l = new ListNode (i);
        p->next = l;
        p = l;
    }
    return dummy->next;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * ans=nullptr;
        ListNode * temp=nullptr;
        while (l1 != nullptr || l2 != nullptr){
            int n1 = l1==nullptr? 0: l1->val;
            int n2 = l2==nullptr? 0: l2->val;
            int sum=n1+n2+carry;
            if ( temp == nullptr){
                temp = new ListNode(sum%10);
                ans = temp;
            }else{
                temp ->next= new ListNode(sum%10);
                temp = temp->next;
            }
            carry = sum/10;
            if (l1 != nullptr){
                l1=l1->next;
            }
            if (l2 != nullptr){
                l2=l2->next;
            }
        }
        if (carry>0){
            temp->next = new ListNode(carry);
        }
        return ans;
    }


    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * ans=nullptr;
        ListNode * pre=nullptr;
        ListNode * temp=new ListNode();
        ans = temp;
        while (l1 != nullptr || l2 != nullptr){
            int n1 = l1==nullptr? 0: l1->val;
            int n2 = l2==nullptr? 0: l2->val;
            int sum=n1+n2+carry;
            temp ->val= sum%10;
            temp ->next= new ListNode();
            pre=temp;
            temp = temp->next;
            carry = sum/10;
            if (l1 != nullptr){
                l1=l1->next;
            }
            if (l2 != nullptr){
                l2=l2->next;
            }
        }
        if (carry>0){
            temp->val = carry;
        }
        else{
            pre->next = nullptr;
        }
        return ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    ListNode * list0 = new ListNode(0);
    ListNode * list1 = new ListNode(1);
    ListNode * list2 = new ListNode(2);

    vec2list({1,2,3,4},list0);
    vec2list({2,4,5,9},list1);
    print_list(list0);
    print_list(list1);
    print_list(entity.addTwoNumbers2(list0,list1));

    list2=vec2list({1,2,3,4,5});
    print_list(list2);
    return 0;
}
