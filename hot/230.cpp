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

class MyBst{
    private:
        TreeNode* root;
        unordered_map<TreeNode*, int> mp;

        int countNode(TreeNode* root){
            if ( root == nullptr){
                return 0;
            }

            mp[root] = 1+ countNode(root->left) + countNode(root->right);
            return mp[root];
        }

        int getNodeNum(TreeNode* node){
            if(node!= nullptr && mp.count(node)){
                return mp[node];
            }else{
                return 0;
            }
        }

    public:
        MyBst(TreeNode* root){
            this->root = root;
            countNode(root);
        }

        int kthSmallest(int k){
            TreeNode* node = root;
            while (node != nullptr){
                int num = getNodeNum(node->left);
                if (num == k-1){
                    break;
                }else if ( num > k-1){
                    node = node->left;
                }else{
                    node = node->right;
                    k-= num+1;
                }
            }
            return node->val;
        }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack <TreeNode*> sta;
        while (!sta.empty()|| root!=nullptr){
            while (root!=nullptr){
                sta.push(root);
                root=root->left;
            }
            root=sta.top();
            sta.pop();
            k--;
            if (k==0){
                break;
            }
            root=root->right;
        }
        return root->val;
    }


    int kthSmallest2(TreeNode* root, int k) {
        // 通过子树的节点数量计算
        MyBst bst(root);
        return bst.kthSmallest(k);
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector <int> tree_vec={1,2,2,3,4,4,3};

    TreeNode* root = vec2tree(tree_vec);
    print_tree(root);
    cout << entity.kthSmallest2(root,2);
    // print_tree(root);

    return 0;
}
