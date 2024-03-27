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
    bool check_sym(TreeNode* l, TreeNode* r){
        if ( !l && !r) return true;
        else if ( !l || !r) return false;
        return l->val == r->val && check_sym(l->left,r->right) && check_sym(l->right,r->left) ;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return check_sym(root->left,root->right);
    }

    bool isSymmetric2(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode * l = q.front();
            q.pop();
            TreeNode * r = q.front();
            q.pop();
            if (!l && !r) continue;
            if ( (!l || !r) || l ->val != r->val) return false;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
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
    cout << entity.isSymmetric2(root) << endl;
    print_tree(root);

    return 0;
}
