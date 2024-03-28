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
    void preorder(TreeNode* root, queue<TreeNode*> &q){
        if (root==nullptr){
            return ;
        }
        q.push(root);
        preorder(root->left,q);
        preorder(root->right,q);
    }

    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        preorder(root,q);

        TreeNode * dummy=new TreeNode();
        dummy->right=root;
        while (!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            // cout << curr->val << ",";
            dummy->right=curr;
            // curr->left=dummy;
            curr->left=nullptr;
            dummy=curr;
        }
        return ;
    }


    void flatten2(TreeNode* root) {
        // 迭代法
        stack<TreeNode*> sta;
        sta.push(root);
        TreeNode * prev=nullptr;
        while (!sta.empty()){
            TreeNode* curr = sta.top();
            sta.pop();
            if(prev!=nullptr){
                prev->left=nullptr;
                prev->right=curr;
            }
            if ( curr==nullptr){
                continue;
            }
            if ( curr->right!= nullptr) sta.push(curr->right);
            if ( curr->left!= nullptr) sta.push(curr->left);
            prev = curr;
        }
    }


    void flatten3(TreeNode* root) {
        TreeNode* curr=root;
        while (curr!= nullptr){
            if(curr->left!=nullptr){
                TreeNode* next = curr->left;
                TreeNode* prev = next;
                while (prev->right!=nullptr){
                    prev=prev->right;
                }
                prev->right = curr->right;
                curr->left=nullptr;
                curr->right=next;
            }
            curr=curr->right;
        }
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector <int> tree_vec={1,2,2,3,4,4,3,6};

    TreeNode* root = vec2tree(tree_vec);
    print_tree(root);
    entity.flatten3(root);
    print_tree(root);
    cout << tree_vec.size() << endl;
    for (int i : tree_vec){
        cout << i << " ";
    }

    return 0;
}
