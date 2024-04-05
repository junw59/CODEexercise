#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>

using namespace std;


class MinStack {
private:
    stack<int> sta;
    stack<int> min_sta;
public:
    MinStack() {
        min_sta.push(INT_MAX);
    }

    void push(int val) {
        sta.push(val);
        min_sta.push(min(val,min_sta.top()));
    }

    void pop() {
        sta.pop();
        min_sta.pop();
    }

    int top() {
        return sta.top();
    }

    int getMin() {
        return min_sta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main(){
    // Solution entity;
    cout << "hello world" << endl;

    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin();   // --> 返回 -3.
    minStack.pop();
    cout << minStack.top();      // --> 返回 0.
    cout << minStack.getMin();   // --> 返回 -2.

    return 0;
}