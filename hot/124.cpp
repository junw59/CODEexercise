#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* vec2tree(vector <int> &vec){
    TreeNode* root=new TreeNode(vec.front());
    queue<TreeNode *> q;
    q.push(root);
    int i =1;
    int n = vec.size();
    while (!q.empty() && i < n){
        TreeNode* cur = q.front();
        q.pop();
        if(i<n && vec[i]!=INT16_MIN){
            cur->left = new TreeNode(vec[i]);
            q.push(cur->left);
        }
        i++;
        if(i<n && vec[i]!=INT16_MIN){
            cur->right = new TreeNode(vec[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

void print_tree(TreeNode* root){
    queue <TreeNode *> q;
    q.push(root);
    while (!q.empty()){
        int sz = q.size();
        while (sz >0){
            TreeNode* temp = q.front();
            q.pop();
            if (temp == nullptr){
                cout << "x" << "  ";
            }else{
                cout << temp->val << "  ";
                q.push(temp->left);
                q.push(temp->right);
            }
            sz--;
        }
        cout << endl;
    }
}


class Solution {
public:
    int maxSum = INT_MIN;
    int maxGain(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left = max(maxGain(root->left),0);
        int right = max(maxGain(root->right),0);
        int curr=root->val + left+right;
        maxSum=max(maxSum,curr);
        return root->val + max(left,right);
    }


    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector <int> tree_vec={3,5,1,6,2,0,8,INT16_MIN,INT16_MIN,7,4};

    TreeNode* root = vec2tree(tree_vec);
    print_tree(root);
    cout << entity.maxPathSum(root);

    return 0;
}
