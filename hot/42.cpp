#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left=0,right=n-1;
        int left_max = 0,right_max = 0;
        while (left < right){
            left_max = max(left_max,height[left]);
            right_max = max(right_max,height[right]);
            if ( height[left] < height[right]){
                ans += left_max - height[left];
                left ++;
            }
            else{
                ans += right_max - height[right];
                right --;
            }
        }
        return ans;
    }
};




int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> nums={1,1};
    int ans=entity.trap(nums);
    cout << ans << " ";
}