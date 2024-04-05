#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 枚举各种宽度来计算
        int n =heights.size();
        int ans=0;

        for ( int left =0; left<n; left++){
            int min_h = INT_MAX;
            for( int right = left; right<n; right++){
                min_h = min(min_h,heights[right]);
                ans = max(ans, (right-left+1)*min_h);
            }
        }
        return ans;
    }


    int largestRectangleArea2(vector<int>& heights) {
        // 枚举各种高度来计算
        int n =heights.size();
        int ans=0;

        for ( int mid =0; mid<n; mid++){
            int h = heights[mid];
            int l=mid,r=mid;
            // 分别向左右移动，确定当前的高度对应的最大宽度
            while(l-1>=0 && heights[l-1]>=h) l--;
            while(r+1<n && heights[r+1]>=h) r++;
            ans = max(ans, (r-l+1)*h);
        }
        return ans;
    }

    int largestRectangleArea2s(vector<int>& heights) {
        // 枚举各种高度来计算，同时使用栈来获取每个高度对应的左右最低位置
        int n =heights.size();
        int ans=0;
        vector<int> left(n), right(n);
        stack <int> mono;

        for (int i =0; i< n; i++){
            while(!mono.empty() && heights[mono.top()]>=heights[i]){
                mono.pop();
            }
            left[i] = (mono.empty()? -1: mono.top());
            mono.push(i);
        }

        mono=stack<int> ();
        for (int i =n-1; i>=0; i--){
            while(!mono.empty() && heights[mono.top()]>=heights[i]){
                mono.pop();
            }
            right[i] = (mono.empty()? n: mono.top());
            mono.push(i);
        }

        for ( int mid =0; mid<n; mid++){
            // 分别向左右移动，确定当前的高度对应的最大宽度
            ans = max(ans, (right[mid]-left[mid]-1)*heights[mid]);
        }
        return ans;
    }
};

int main(){
    Solution entity;
    cout << "hello world" << endl;
    vector<int> nums={2,1,5,6,2,3};
    vector<int> results;
    cout << entity.largestRectangleArea2(nums);
    cout << entity.largestRectangleArea2s(nums);
    // for (auto i : results){
    //     cout << i << endl;
    // }

    return 0;
}