#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0,right=n-1, ans=0;
        while (right>left){
            int area=min(height[left],height[right])*(right-left);
            ans = max(ans, area);
            if (height[left]<height[right]) left++;
            else right--;
        }
        return ans;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={1,8,6,2,5,4,8,3,7};
    // vector<int> nums={1,1};
    int ans=entity.maxArea(nums);
    cout << ans << " ";
}