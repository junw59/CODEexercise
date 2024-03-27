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
    bool isValidBST(TreeNode* root) {
        return bet_val(root,LONG_MIN,LONG_MAX);
    }

    bool bet_val(TreeNode* root, long long left, long long right){
        if ( root == nullptr){
            return true;
        }
        if (root->val <= left ||root->val >= right){
            return false;
        }
        return bet_val(root->left, left, root->val) && bet_val(root->right,root->val, right);
    }


    bool isValidBST2(TreeNode* root) {
        stack <TreeNode*> sta;
        long long in_order = (long long) INT_MIN-1;
        while (!sta.empty() || root!= nullptr){
            while (root!=nullptr){
                sta.push(root);
                root=root->left;
            }
            root = sta.top();
            sta.pop();
            if ( root->val <= in_order){
                return false;
            }
            in_order = root->val;
            root = root->right;
        }
        return true;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector <int> tree_vec={1,2,2,3,4,4,3};

    TreeNode* root = vec2tree(tree_vec);
    print_tree(root);
    cout << entity.isValidBST2(root);
    // print_tree(root);

    return 0;
}
