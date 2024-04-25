#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
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
    void dfs(TreeNode* root, unordered_map<int, vector<int>> &mp){
        vector<TreeNode*> nodes ={root->left,root->right};
        for(TreeNode* child : nodes){
            if(child!=nullptr){
                mp[child->val].push_back(root->val);
                mp[root->val].push_back(child->val);
                dfs(child,mp);
            }
        }
        return;
    }

    void bfs(TreeNode* root, unordered_map<int, vector<int>> &mp){
        queue<TreeNode*> q;
        q.push(root);
        // visited.insert(root->val);
        while(!q.empty()){
            int idx = q.size();
            while( idx--){
                TreeNode* curr = q.front();
                q.pop();
                vector<TreeNode*> nodes ={curr->left,curr->right};
                for(TreeNode* child : nodes){
                    if(child!=nullptr){
                        mp[child->val].push_back(curr->val);
                        mp[curr->val].push_back(child->val);
                        q.push(child);
                    }
                }

            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> mp;
        unordered_set<int> visited;
        // dfs(root,mp);
        // 预防栈溢出可以使用bfs
        bfs(root,mp);

        queue<int> q;
        q.push(start);
        visited.insert(start);
        int max_len=-1;
        while(!q.empty()){
            int idx = q.size();
            // cout << "idx:" << idx << endl;
            ++max_len;
            while (idx--){
                // --idx;
                int curr=q.front();
                q.pop();
                visited.insert(curr);
                for(auto x: mp[curr]){
                    if (visited.count(x)>0) continue;
                    q.push(x);
                }
            }
        }
        return max_len;
    }
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


int main(){
    cout << "hello world" << endl;
    vector <int> tree_vec={1,5,3,-1,4,10,6,9,2};
    TreeNode* root = vec2tree(tree_vec);
    Solution entity;
    cout << entity.amountOfTime(root,3) << endl;

    return 0;
}