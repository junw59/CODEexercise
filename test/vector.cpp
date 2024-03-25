#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int main(){
    cout << "hello world" << endl;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums2={1,-3,4,-1,2,1,-5,4};

    if (nums<nums2){
        cout << "nums2" << endl;
    }
    else
        cout << "nums" << endl;


    return 0;
}