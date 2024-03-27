#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

struct DlinkNode
{
    int key, value;
    DlinkNode* prev;
    DlinkNode* next;
    DlinkNode(): key(0),value(0),prev(nullptr),next(nullptr){};
    DlinkNode(int _key,int _value): key(_key),value(_value),prev(nullptr),next(nullptr){};
};


class LRUCache {
private:
    unordered_map<int,DlinkNode*> cache;
    DlinkNode* head=new DlinkNode();
    DlinkNode* tail=new DlinkNode();
    int size;
    int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
        size=0;
        // head=new DlinkNode();
        // tail=new DlinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(cache.count(key)==0){
            return -1;
        }
        DlinkNode* node = cache[key];
        move2head(node);
        return node->value;
    }

    void put(int key, int value) {
        if(cache.count(key)>0){
            DlinkNode* node = cache[key];
            node->value=value;
            move2head(node);
        }
        else{
            DlinkNode* node = new DlinkNode (key, value);
            add2head(node);
            cache[key]=node;
            size++;
            if (size>cap){
                DlinkNode* node = tail->prev;
                remove(node);
                cache.erase(node->key);
                delete node;
                size--;
            }
        }
    }

    void add2head(DlinkNode * node){
        node->next = head->next;
        node->prev = head;
        node->next->prev=node;
        head->next=node;
    }
    void remove(DlinkNode * node){
        if(node!=nullptr && node->next!=nullptr){
            node->next->prev=node->prev;
            node->prev->next=node->next;
        }
    }
    void move2head(DlinkNode * node){
        remove(node);
        add2head(node);
    }

    void print_cache(){
        DlinkNode* temp = head->next;
        while (temp != tail){
            cout << temp->key << " " << temp->value << ";";
            temp = temp->next;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){
    cout << "hello world" << endl;
    LRUCache entity(5);
    entity.put(1,102);
    entity.put(5,602);
    entity.print_cache();

    return 0;
}
