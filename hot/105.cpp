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
private:
    unordered_map <int, int> mp;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n =inorder.size();
        for (int i =0; i<n; i++){
            mp[inorder[i]]=i;
        }
        return buildTreeBetween(preorder,inorder,0,n-1,0,n-1);
    }

    TreeNode* buildTreeBetween(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if(preL>preR){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[preL]);
        int first = mp[preorder[preL]];
        int left_l = first - inL;

        root->left=buildTreeBetween(preorder,inorder,preL+1,preL+left_l,inL,first-1);
        root->right=buildTreeBetween(preorder,inorder,preL+left_l+1,preR,first+1,inR);

        return root;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector <int> pre={3,9,20,15,7};
    vector <int> ino={9,3,15,20,7};

    TreeNode* root =entity.buildTree(pre,ino);
    print_tree(root);

    return 0;
}
