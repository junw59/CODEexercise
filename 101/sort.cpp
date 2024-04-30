#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;


// 快速排序：quick_sort
void quick_sort(vector<int> &nums, int left, int right){
    // 范围一样的情况下就选择跳过
    if(left >= right){
        return ;
    }

    // 先挑选一个基准的值 key
    int first = left, last = right;
    int key = nums[first];
    while(first < last){
        // 从右边寻找比基准值小的数
        while (first<last && nums[last]>= key){
            --last;
        }
        // 挪到左边
        nums[first] = nums[last];

        // 从左边寻找比基准值大的数
        while (first<last && nums[first]<= key){
            ++first;
        }
        // 挪到右边
        nums[last] = nums[first];
    }

    // 直到两个指针 first, last 相遇，将基准值放入左边，这就是他的正确位置
    nums[first]=key;
    quick_sort(nums, left, first-1);
    quick_sort(nums, first+1, right);
}


// 归并排序 merge_sort
void merge_sort(vector<int> &nums, int left, int right, vector<int> &temp){
    // 范围一样的情况下就选择跳过
    if(left >= right){
        return ;
    }

    // 分别排序左右两边的元素
    int mid = left + (right-left)/2;
    merge_sort(nums, left, mid, temp);
    merge_sort(nums, mid+1, right, temp);

    // 将两个区间中排序好的部分重新合并,到指定的temp数组
    int item1 = left, item2= mid+1, item_t=left;
    while(item1 <= mid || item2 <= right){
        // 挑选更小的元素放到temp数组中
        if( item2 > right || (item1 <=mid && nums[item1] <= nums[item2])){
            temp[item_t++] = nums[item1++];
        }else {
            temp[item_t++] = nums[item2++];
        }
    }
    // 将排序完成的数组复制到原来的数组
    for (item_t = left; item_t <= right; ++ item_t){
        nums[item_t] = temp[item_t];
    }
}


// 插入排序 insert_sort
void insert_sort(vector<int> &nums){
    int n =nums.size();
    for(int i=0; i<n; ++i){
        // 从i开始向前,交换所有出现的相邻的大小不一致的数对
        for(int j=i; j>0 && nums[j]<nums[j-1]; --j){
            swap(nums[j],nums[j-1]);
        }
    }
}



// 希尔排序 shell_sort
void shell_sort(vector<int> &nums){
    int n =nums.size();
    // 每次选择将相距gap的元素做一次插入排序
    // gap每次减半
    for( int gap = n>>1 ; gap>0; gap>>=1){
        // 做插入排序
        for(int i = 0; i<n; ++i){
            // 从i开始向前把相邻大小不一致的交换
            for( int j =i; j>=gap && nums[j]<nums[j-gap]; j-=gap){
                swap(nums[j],nums[j-gap]);
            }
        }
    }
}



// 冒泡排序 bubble_sort
void bubble_sort(vector<int> &nums){
    int n =nums.size();
    // 每次遍历将最大的数放到最后
    for (int i =0; i <n; ++i){
        // 每次遍历时,只用遍历到n-i,后面的已经排好了
        for(int j=1; j<n-i; ++j){
            if(nums[j-1]>nums[j]){
                swap(nums[j-1],nums[j]);
            }
        }
    }
}


// 选择排序 selection_sort
void selection_sort(vector<int> &nums){
    int n =nums.size();
    int mini;
    // 每次循环将最小的数放到最前面
    for(int i=0; i<n; ++i){
        mini=i;
        for(int j=i+1; j<n; ++j){
            if(nums[j]<nums[mini]){
                mini=j;
            }
        }
        swap(nums[mini],nums[i]);
    }
}




// 堆排序 heap_sort
// 调整最大堆中的父子节点的大小关系, 调整的范围仅限 start 到 end
void max_heap(vector<int> &nums, int start, int end){
    int dad = start;
    int son = dad*2+1;
    while(son <= end){
        // 如果另一个子节点存在,选择更大的节点
        if(son +1 <=end && nums[son]<nums[son+1]){
            ++son;
        }
        // 父节点更大,不需要继续了
        if(nums[dad] > nums[son]){
            return ;
        }else{
            // 父节点更小就交换它们,然后继续向下把小的节点放下去
            swap(nums[dad],nums[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}

void heap_sort(vector<int> &nums){
    int n =nums.size();

    // 首先要整一个最大堆,堆节点i的子节点是 2i+1,2i+2, 父节点就是 (i-1)/2
    // 从最后一个父节点(n-1-1)/2开始处理最大堆,这样可以让最大值不断上浮
    for(int i = n/2-1; i>=0; --i){
        max_heap(nums, i, n-1);
    }

    // 每次把最大的值放到最后
    for(int i=n-1; i>0; --i){
        swap(nums[0],nums[i]);
        // 重新构建最大堆,从0到i-1,因为i以及之后的已经排好序
        max_heap(nums, 0, i-1);
    }
}


// 计数排序 counting_sort
void counting_sort(vector<int> &nums){
    int n =nums.size();
    // 先找到最大最小值
    int mini=INT_MAX, maxi=INT_MIN;
    for (int i=0; i<n; ++i){
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }

    // 在最大和最小值之间将数组元素计数
    vector<int> count_vec(maxi-mini,0);
    for (int i=0; i<n; ++i){
        ++count_vec[nums[i]-mini];
    }

    // 按照计数得到的大小重新排序原来的数组
    int idx=0;
    for(int i=mini; i<=maxi; ++i){
        while( count_vec[i-mini]-- ){
            nums[idx++] = i-mini;
        }
    }
}


// 桶排序 bucket_sort
void bucket_sort(vector<int> &nums){
    int n =nums.size();
    int mini=INT_MAX, maxi=INT_MIN;
    for (int i=0; i<n; ++i){
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }

    int buck_n=10;
    vector<vector<int>> bucket_s(buck_n);
    int size_b=(maxi-mini)/buck_n+1;
    for (int i=0; i<n; ++i){
        bucket_s[(nums[i]-mini)/size_b].push_back(nums[i]);
    }

    for(int i =0; i< buck_n; ++i){
        insert_sort(bucket_s[i]);
    }

    int idx=0;
    for(int i =0; i< buck_n; ++i){
        for (auto x: bucket_s[i]){
            nums[idx++]=x;
        }
    }


}


// 基数排序 radix_sort



int main(){
    cout << "hello world" << endl;
    vector<int> nums = {1,3,4,6,8,20,2,0,10,5};
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;

    int n=nums.size();
    // quick_sort(nums, 0, n-1);
    // vector<int> temp(n);
    // merge_sort(nums, 0, n-1, temp);
    // insert_sort(nums);
    // shell_sort(nums);
    // bubble_sort(nums);
    // selection_sort(nums);
    // counting_sort(nums);
    // heap_sort(nums);
    bucket_sort(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;


}