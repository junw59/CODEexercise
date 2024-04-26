#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class SnapshotArray {
private:
    vector<int> arr;
    vector<vector<int>> arr_snap;
    int snap_num;
public:
    SnapshotArray(int length) {
        arr.resize(length,0);
        snap_num=0;
    }

    void set(int index, int val) {
        if(index < arr.size()){
            arr[index]=val;
        }
    }

    int snap() {
        // 每个快照都复制一份太费内存了
        arr_snap.push_back(arr);
        return snap_num++;
    }

    int get(int index, int snap_id) {
        return arr_snap[snap_id][index];
    }
};


class SnapshotArray2 {
private:
    unordered_map<int,int> arr;
    vector<unordered_map<int,int>> arr_snap;
    int snap_num;
public:
    SnapshotArray2(int length) {
        // arr.resize(length,0);
        snap_num=0;
    }

    void set(int index, int val) {
        arr[index]=val;
    }

    int snap() {
        // 每个快照都复制一份hash函数太费内存了
        arr_snap.push_back(arr);
        return snap_num++;
    }

    int get(int index, int snap_id) {
        return arr_snap[snap_id][index];
    }
};

class SnapshotArray3 {
private:
    vector<vector< pair<int,int>>> arr_snap;
    int snap_num=0;
public:
    SnapshotArray3(int length) {
        arr_snap.resize(length);
    }

    void set(int index, int val) {
        arr_snap[index].push_back({snap_num,val});
    }

    int snap() {
        return snap_num++;
    }

    int get(int index, int snap_id) {
        // auto idx = upper_bound(arr_snap[index].begin(),arr_snap[index].end(), pair { snap_id + 1, -1} );
        auto idx = upper_bound(arr_snap[index].begin(),arr_snap[index].end(), make_pair(snap_id+1,-1) );
        return idx == arr_snap[index].begin()? 0: (--idx)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
*/


int main(){
    cout << "hello world" << endl;
    // SnapshotArray snapshotArr = SnapshotArray(3); // 初始化一个长度为 3 的快照数组
    SnapshotArray3 snapshotArr = SnapshotArray3(3); // 初始化一个长度为 3 的快照数组
    snapshotArr.set(0,5);  // 令 array[0] = 5
    cout << snapshotArr.snap() << endl;  // 获取快照，返回 snap_id = 0
    snapshotArr.set(0,6);
    cout << snapshotArr.get(0,0) << endl;  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5

}