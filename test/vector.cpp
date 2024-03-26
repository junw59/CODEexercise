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

    for (auto i:nums){
        cout << i << " ";
    }
    cout << endl;

    vector<vector<int>> nums2d={{1,-3},{4,-1},{2,1},{-5,4}};
    // nums2d.push_back({0,2});
    nums2d.emplace_back(vector<int> {0,2});
    for (auto i:nums2d){
        for (auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }




    return 0;
}