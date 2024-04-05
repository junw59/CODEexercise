#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int quick_sel(vector<int> &nums, int k, int l, int r) {
        if (l == r) {
            return nums[k];
        }

        int partition = nums[l];
        int i = l-1, j = r+1;
        while (i<j){
            // cout << i << j << endl;
            do i++; while (nums[i]<partition);
            do j--; while (nums[j]>partition);
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }

        if (k<=j) {
            return quick_sel(nums, k, l, j);
        }else {
            return quick_sel(nums, k, j+1, r);
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        return quick_sel(nums, n - k, 0, n - 1);
    }


    // 使用大根堆来实现
    void max_heap_fy(vector<int> &nums, int i, int hs){
        // 构建的是从i开始，共有hs那么多的元素
        int l = 2*i+1, r=2*i+2;
        int largest = i;
        if( l < hs && nums[l] > nums[largest]){
            largest = l;
        }
        if( r < hs && nums[r] > nums[largest]){
            largest = r;
        }
        if( largest !=i){
            swap(nums[i],nums[largest]);
            // 将换下去的元素继续往后排
            max_heap_fy(nums,largest,hs);
        }
    }

    void build_heap(vector<int> &nums, int hs){
        for(int i = hs/2-1; i >=0; i--){
            max_heap_fy(nums,i,hs);
        }
    }

    int findKthLargest2(vector<int> &nums, int k) {
        int hs = nums.size();
        build_heap(nums, hs);
        // 需要扔掉k-1个最大值，就是需要的第k大的数 i=n; i>= n-(k-1)+1
        for ( int i = nums.size()-1; i >= nums.size()-k+1; i--){
            // 交换最大和最后的
            swap(nums[0],nums[i]);
            // 除了最后一个元素，其他的重新排列
            hs--;
            max_heap_fy(nums,0,hs);
        }

        return nums[0];
    }

};

int main() {
    Solution entity;
    vector<int> nums = {3,2,1,5,6,4};
    cout << "hello world" << endl;
    cout << entity.findKthLargest(nums,2);
    cout << entity.findKthLargest2(nums,2);

    return 0;
}