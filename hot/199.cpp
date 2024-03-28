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
    vector<int> rightSideView(TreeNode* root) {
        // 广度优先算法 bfs 
        vector <int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while ( !q.empty()){
            int sz = q.size();
            while (sz>0){
                TreeNode* curr = q.front();
                q.pop();
                if(curr!=nullptr){
                    if (sz==1){
                        ans.push_back(curr->val);
                    }
                    if (curr->left !=nullptr ) q.push(curr->left);
                    if (curr->right !=nullptr ) q.push(curr->right);
                }
                sz--;
            }
        }
        return ans;
    }


    void dfs(TreeNode* node, vector<int> &ans, int depth){
        if (node == nullptr) return ;
        if (ans.size()<depth){
            ans.push_back(node->val);
        }
        dfs(node->right,ans,depth+1);
        dfs(node->left,ans,depth+1);
    }
    vector<int> rightSideView2(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans,1);
        return ans;
    }

    vector<int> rightSideView3(TreeNode* root) {
        // 深度优先算法 dfs, 打印val
        unordered_set<int> mp;
        vector<int> ans;
        int maxDepth = 0;
        stack<TreeNode*> sta;
        stack<int> depth;
        sta.push(root);
        depth.push(0);
        int currDepth = 0;
        while (!sta.empty()){
            TreeNode * curr = sta.top();
            sta.pop();
            currDepth = depth.top();
            depth.pop();
            if( curr != nullptr){
                if (mp.count(currDepth)==0){
                    ans.push_back(curr->val);
                    mp.insert(currDepth);
                }
                cout << curr->val << " ";
                sta.push(curr->left);
                sta.push(curr->right);
                depth.push(currDepth+1);
                depth.push(currDepth+1);
            }
        }
        return ans;
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector <int> tree_vec={1,2,2,3,4,4,3,6};

    TreeNode* root = vec2tree(tree_vec);
    print_tree(root);
    tree_vec = entity.rightSideView2(root);
    cout << tree_vec.size() << endl;
    for (int i : tree_vec){
        cout << i << " ";
    }

    return 0;
}
