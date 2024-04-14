#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>

using namespace std;


class MyHashSet {
private:
    vector < list<int> > data;
    int base =101;
    int hash(int key){
        return key%base ;
    }
public:
    MyHashSet() {
        data.resize(base);
    }

    void add(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it){
            if(*it == key){
                return ;
            }
        }
        data[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it){
            if(*it == key){
                data[h].erase(it);
                return ;
            }
        }
    }

    bool contains(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it){
            if(*it == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
*/


int main(){
    cout << "hello world" << endl;
    MyHashSet myHashSet = MyHashSet();
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    cout << myHashSet.contains(1) << endl; // 返回 True
    cout << myHashSet.contains(3) << endl; // 返回 False ，（未找到）
    myHashSet.add(2);      // set = [1, 2]
    cout << myHashSet.contains(2) << endl; // 返回 True
    myHashSet.remove(2);   // set = [1]
    cout << myHashSet.contains(2) << endl; // 返回 False ，（已移除）

    return 0;
}