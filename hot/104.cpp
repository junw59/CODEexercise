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
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }


    int maxDepth2(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz >0)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                sz--;
            }
            ans++;
        }
        return ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector <int> tree_vec={1,-1,2,3};
    vector <int> tree_vec={3,9,20,-1,-1,15,7};
    // TreeNode* root = new TreeNode(1);
    // root->right=new TreeNode(2);
    // root->right->left=new TreeNode(3);

    TreeNode* root = vec2tree(tree_vec);
    int res=entity.maxDepth2(root);
    cout << res ;

    return 0;
}
