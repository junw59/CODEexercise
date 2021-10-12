#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int lo, int hi){
        if (lo > hi) return nullptr;

        int index = -1;
        int maxval = INT_MIN;
        for ( int i = lo; i <= hi; i++){
            if (maxval < nums[i]){
                index = i;
                maxval = nums[i];
            }
        }

        TreeNode* root = new TreeNode(maxval);
        root->left = build(nums, lo, index - 1);
        root->right = build(nums, index + 1, hi);

        return root;
    }
};

void forward(TreeNode* root){
    if (root == nullptr) {
        cout << "null" << "\t";
        return;
    }
    cout << root->val << "\t";
    forward(root->left);
    forward(root->right);
    return ;
}

int main(){
    // [3,2,1,6,0,5]
    Solution entity;
    vector<int> data = {3,2,1,6,0,5};
    TreeNode* p = entity.constructMaximumBinaryTree(data);
    forward(p);
}