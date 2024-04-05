#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int get_k_element(vector<int>& nums1, vector<int>& nums2, int k){
        // 找俩个数组中，第k小的数
        int idx_1 = 0;
        int idx_2 = 0;
        int n1= nums1.size();
        int n2= nums2.size();

        while (true){
            if( idx_1 == n1){
                return nums2[idx_2+k-1];
            }
            if( idx_2 == n2){
                return nums1[idx_1+k-1];
            }
            if(k==1){
                return min(nums1[idx_1],nums2[idx_2]);
            }

            // 往右边移动指标
            int new_i1= min(idx_1+k/2-1,n1-1);
            int new_i2= min(idx_2+k/2-1,n2-1);

            if(nums1[new_i1]<=nums2[new_i2]){
                // 放弃nums1左边的数
                k-=new_i1-idx_1+1;
                idx_1=new_i1+1;
            }else{
                k-=new_i2-idx_2+1;
                idx_2=new_i2+1;
            }
        }
        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_l = nums1.size()+nums2.size();
        if(total_l%2==1){
            return get_k_element(nums1, nums2, total_l/2+1);
        }else{
            return (get_k_element(nums1, nums2, total_l/2)+get_k_element(nums1, nums2, total_l/2+1))/2.0;
        }
    }
};


int main(){
    Solution entity;
    vector<int> nums1={1,3};
    vector<int> nums2={2};
    cout << "hello world" << endl;
    cout<< entity.findMedianSortedArrays(nums1,nums2);
    return 0;
}