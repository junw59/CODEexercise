#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// /**
//  * Definition for a binary tree node.
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue <TreeNode> q;
        q.push(*root);
        int depth=1;
        while( !q.empty()){
            int sz = q.size();

            for ( int i = 0; i < sz; i++){
                TreeNode cur = q.front();
                q.pop();

                if( cur.left == nullptr && cur.right == nullptr) return depth;

                if( cur.left != nullptr) q.push(*cur.left);
                if( cur.right != nullptr) q.push(*cur.right);
            }

            depth++;
        }

        return depth;
    }
};



int main(){
    Solution entity;
    TreeNode l1(9);
    TreeNode l3(15);
    TreeNode l4(7);
    TreeNode l2(20,&l3,&l4);
    TreeNode test(3,&l1,&l2);
    // [3,9,20,null,null,15,7]

    cout << "hello world" << endl;
    int depth=entity.minDepth(&test);

    cout << depth << endl;
}