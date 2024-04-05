#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;



class MedianFinder {
public:
    priority_queue <int , vector <int>, less<int> > que_min;
    priority_queue <int , vector <int>, greater<int> > que_max;

    MedianFinder() {}

    void addNum(int num) {
        if(que_min.empty() || num <= que_min.top()){
            que_min.push(num);
            if ( que_max.size() +1 < que_min.size()){
                que_max.push(que_min.top());
                que_min.pop();
            }
        } else {
            que_max.push(num);
            if ( que_max.size() > que_min.size()){
                que_min.push(que_max.top());
                que_max.pop();
            }
        }
    }

    double findMedian() {
        if(que_max.size() < que_min.size()){
            return que_min.top();
        }else {
            return (que_min.top()+que_max.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main() {
    // Solution entity;
    cout << "hello world" << endl;
    MedianFinder medianFinder = MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    cout << medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    cout << medianFinder.findMedian(); // return 2.0

    return 0;
}