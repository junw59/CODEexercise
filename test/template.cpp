#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <stdio.h>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

template <typename elemType>
class BinaryTree;


// 二叉树节点的定义
template <typename valType>
class BTnode {
private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
public:
    friend class BinaryTree <valType>;
    BTnode();
    BTnode(const valType &val);
    ~BTnode();
    void insert_value(const valType &val) ;
    // 声明为静态函数，方便BTree调用
    static void lchild_leaf(BTnode *leaf, BTnode * subtree) ;
    void remove_value(const valType &val, BTnode *& prev);
    void preorder(BTnode *pt, ostream &os) const;
    void display(BTnode *pt, ostream &os) const;
};

template <typename valType>
BTnode<valType>::BTnode() {}

// 成员初始化列表比较合适
template <typename valType>
inline BTnode<valType>::BTnode(const valType &val):_val(val) {
    _cnt=1;
    _lchild=_rchild=0;
}

template <typename valType>
BTnode<valType>::~BTnode() {}

template <typename valType>
void BTnode<valType>::
insert_value(const valType &val){
    if(val==_val){
        ++_cnt;
        return;
    } else if (val <_val){
        if(!_lchild){
            _lchild = new BTnode (val);
        } else {
            _lchild->insert_value(val);
        }
    }else{
        if(!_rchild){
            _rchild = new BTnode (val);
        } else {
            _rchild->insert_value(val);
        }
    }
    return ;
}

// 把左子树移动到右子数的左叶子上
template <typename valType>
void BTnode<valType>::
lchild_leaf(BTnode *leaf, BTnode * subtree){
    while( subtree-> _lchild){
        subtree = subtree->_lchild;
    }
    subtree->_lchild = leaf;
}


template <typename valType>
void BTnode<valType>::
remove_value(const valType &val, BTnode *& prev){
    if( val<_val){
        if(!_lchild){
            return ;
        } else {
            _lchild ->remove_value(val, _lchild);
        }
    } else if (val>_val){
        if(!_rchild){
            return ;
        } else {
            _rchild ->remove_value(val, _rchild);
        }
    } else {
        if(_rchild){
            // 更改传入的节点
            prev = _rchild;
            if (_lchild){
                if(! prev ->_lchild){
                    prev ->_lchild = _lchild;
                }else {
                    BTnode <valType> :: lchild_leaf(_lchild, prev->_lchild);
                }
            }
        }else {
            prev = _lchild;
        }
        delete this;
    }
    return ;
}


template <typename valType>
void BTnode<valType>::
display(BTnode *pt, ostream &os) const {
    os << pt->_val << " ";
    return ;
}

template <typename valType>
void BTnode<valType>::
preorder(BTnode *pt, ostream &os) const {
    if(pt){
        display(pt,os);
        if(pt->_lchild) {
            preorder(pt->_lchild, os);
        }
        if(pt->_rchild){
            preorder(pt->_rchild, os);
        }
    }
    return ;
}




// 二叉树的定义
template <typename elemType>
class BinaryTree {
private:
    BTnode<elemType> *_root;
    void copy(BTnode<elemType> *tar, BTnode<elemType> *src);

public:
    BinaryTree();
    BinaryTree(const BinaryTree &);
    ~BinaryTree();

    BinaryTree & operator=(const BinaryTree &);
    bool empty() { return _root==0;}
    void clear();

    void insert_elem(const elemType &elem) ;
    void remove_elem(const elemType &elem) ;
    void remove_root() ;
    void preorder() ;
};

template <typename elemType>
inline BinaryTree <elemType>::
BinaryTree(): _root(0) {}

template <typename elemType>
inline BinaryTree <elemType>::
BinaryTree(const BinaryTree &rhs) {
    copy(_root, rhs._root);
}

template <typename elemType>
inline BinaryTree <elemType>::
~BinaryTree() {
    clear();
}

template <typename elemType>
inline BinaryTree <elemType> &
BinaryTree <elemType>::
operator=(const BinaryTree & rhs){
    if(this!= &rhs){
        clear();
        copy(_root, rhs._root);
    }
    return *this;
}


template <typename elemType>
inline void 
BinaryTree <elemType>::
insert_elem(const elemType &elem){
    if(!_root){
        _root = new BTnode <elemType> (elem);
    }else {
        _root->insert_value(elem);
    }
}


template <typename elemType>
inline void 
BinaryTree <elemType>::
clear(){
    return ;
}


template <typename elemType>
inline void 
BinaryTree <elemType>::
remove_elem(const elemType &elem){
    if(_root){
        if(_root->_val == elem){
            remove_root();
        }else {
            _root->remove_value(elem, _root);
        }
    }
}

template <typename elemType>
inline void 
BinaryTree <elemType>::
remove_root(){
    if(!_root){
        return ;
    }
    BTnode <elemType>  *temp = _root;
    if(_root->_rchild){
        _root = _root->_rchild;

        // 移动左子数到右子树左叶子
        if(temp->_lchild){
            BTnode <elemType> *lc = temp->_lchild;
            BTnode <elemType> *new_lc = _root->_lchild;
            if(!new_lc){
                _root->_lchild = lc;
            } else{
                BTnode<elemType>::lchild_leaf(lc,new_lc);
            }
        }
    }else{
        _root = _root->_lchild;
    }
    delete temp;
}


template <typename elemType>
void BinaryTree <elemType>::
preorder() {
    _root->preorder(_root,cout);
    return ;
}




int main() {
    cout << "hello world!" << endl;
    BTnode<string> bts("42");
    BTnode<int> bti(42);

    BinaryTree<string> bt;
    bt.insert_elem("Pig");
    bt.insert_elem("Eey");
    bt.insert_elem("Roo");
    bt.insert_elem("Tig");
    bt.insert_elem("Chr");
    bt.insert_elem("Poo");
    bt.insert_elem("Kan");

    bt.preorder();

    cout << "\n\n remove: \n";
    bt.remove_elem("Pig");
    bt.preorder();

    cout << "\n\n remove: \n";
    bt.remove_elem("Eey");
    bt.preorder();

}