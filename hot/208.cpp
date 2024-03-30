#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* search_prefix(string pre){
        Trie * node = this;
        for (char ch : pre){
            ch-='a';
            if (node->children[ch]==nullptr){
                return nullptr;
            }
            node = node->children[ch];
        }

        return node;
    }

public:
    Trie() : children(26), isEnd(false){}

    void insert(string word) {
        Trie * node = this;
        for (char ch:word){
            ch-='a';
            if(node->children[ch]==nullptr){
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* sear=search_prefix(word);
        return sear!=nullptr && sear->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* sear=search_prefix(prefix);
        return sear!=nullptr ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    // Trie* obj = new Trie();
    // obj->insert(word);
    // bool param_2 = obj->search(word);
    // bool param_3 = obj->startsWith(prefix);

    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple");   // 返回 True
    cout << trie->search("app");     // 返回 False
    cout << trie->startsWith("app"); // 返回 True
    trie->insert("app");
    cout << trie->search("app");     // 返回 True

    return 0;
}
