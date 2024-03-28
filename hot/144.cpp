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
    void preorder(TreeNode* root, vector<int> &ans){
        // 递归实现前序遍历，中序，后序也是一样的
        if ( root==nullptr){
            return ;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> ans;
        preorder(root,ans);
        return ans;
    }


    vector<int> preorderTraversal2(TreeNode* root) {
        // 迭代实现前序遍历
        vector<int> ans;
        if (root==nullptr){
            return ans;
        }
        stack <TreeNode*> sta;
        TreeNode* curr = root;
        while (curr!=nullptr || !sta.empty()){
            while (curr!=nullptr){
                ans.push_back(curr->val);
                sta.push(curr);
                curr=curr->left;
            }
            curr = sta.top();
            sta.pop();
            curr= curr->right;
        }
        return ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector <int> tree_vec={1,2,5,3,4,7,9,6};

    TreeNode* root = vec2tree(tree_vec);
    print_tree(root);
    tree_vec = entity.preorderTraversal2(root);
    cout << tree_vec.size() << endl;
    for (int i : tree_vec){
        cout << i << " ";
    }

    return 0;
}
