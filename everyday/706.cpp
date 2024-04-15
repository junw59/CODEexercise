#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>

using namespace std;


class MyHashMap {
private:
    vector < list<pair<int,int>> > data;
    int base =101;
    int hash(int key){
        return key%base ;
    }
public:
    MyHashMap() {
        data.resize(base);
    }

    void put(int key, int value) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it){
            if( it->first == key){
                it->second = value;
                return ;
            }
        }
        data[h].push_back({key, value});
    }

    int get(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it){
            if( it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it){
            if( it->first == key){
                data[h].erase(it);
                return ;
            }
        }
    }
};


int main(){
    cout << "hello world" << endl;
    MyHashMap myHashMap =  MyHashMap();
    myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
    myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
    cout << myHashMap.get(1) << endl;    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
    cout << myHashMap.get(3) << endl;    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
    myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
    cout << myHashMap.get(2) << endl;    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
    myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
    cout << myHashMap.get(2) << endl;    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]


    return 0;
}