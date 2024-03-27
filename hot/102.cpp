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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int sz = q.size();
            vector<int> lev;
            while (sz>0){
                TreeNode * temp= q.front();
                q.pop();
                lev.push_back(temp->val);
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
                sz--;
            }
            if (lev.size()>0){
                ans.emplace_back(lev);
            }
        }
        return ans;
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector <int> tree_vec={1,2,2,3,4,4,3};

    TreeNode* root = vec2tree(tree_vec);
    print_tree(root);
    vector<vector<int>> ans=entity.levelOrder(root);
    for ( auto i : ans){
        for ( auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
