#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    int search_edge(vector<int>& nums, int target, bool min_edge) {
        int left = 0;
        int right = nums.size()-1;

        int edge =-1;
        while (left <= right){
            int mid = (left+right)/2;
            if( nums[mid] == target ){
                edge = mid;
                if (min_edge){
                    right = mid-1;
                }else {
                    left = mid+1;
                }
            }else if (nums[mid] > target){
                right = mid-1;
            }else{
                left = mid +1;
            }
        }

        return edge;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = search_edge(nums, target, true);
        int second = search_edge(nums, target, false);

        return {first, second};
    }
};



int main(){
    Solution entity;
    vector<int> nums={5,7,7,8,8,10};
    int target = 8;
    cout << "hello world" << endl;
    vector<int> results;
    results=entity.searchRange(nums, target);
    for (auto i : results){
        cout << i << endl;
    }
    return 0;
}