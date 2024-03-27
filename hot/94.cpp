#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <queue>

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
        if(i<n && vec[i]!=-1){
            cur->left = new TreeNode(vec[i]);
            q.push(cur->left);
        }
        i++;
        if(i<n && vec[i]!=-1){
            cur->right = new TreeNode(vec[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res;
        in_order(root, res);
        return res;
    }

    void in_order(TreeNode* root, vector <int> &res){
        if(root == nullptr){
            return ;
        }
        in_order(root->left, res);
        res.push_back(root->val);
        in_order(root->right, res);
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector <int> tree_vec={1,-1,2,3};
    // TreeNode* root = new TreeNode(1);
    // root->right=new TreeNode(2);
    // root->right->left=new TreeNode(3);

    TreeNode* root = vec2tree(tree_vec);
    vector <int> res=entity.inorderTraversal(root);
    for ( auto i : res){
        cout << i <<" ";
    }

    return 0;
}
