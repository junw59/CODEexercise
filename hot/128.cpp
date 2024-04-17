#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for ( auto & num :nums) num_set.insert(num);

        int longestStreak = 0;
        for (auto & num: num_set){
            // 先检查有没有上一个数，有的话就是已经遍历过的了，直接跳过
            if (!num_set.count(num-1)){
                int current_num = num;
                int current_streak = 1;

                while(num_set.count(current_num+1)){
                    current_num +=1;
                    current_streak +=1;
                }

                longestStreak = max(longestStreak,current_streak);
            }
        }

        return longestStreak;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={100,4,200,1,3,2};
    int results;
    results=entity.longestConsecutive(nums);
    cout << results << endl;

    return 0;
}
