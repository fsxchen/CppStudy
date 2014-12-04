#include <iostream>
using namespace std;
typedef char T;


class bst {
    struct Node{
        T data;
        Node* L;
        Node* R;
        Node(const T&d):data(d),L(),R(){}       //不传参数，就是空
        Node(const T&d, Node* l, Node* r):data(d), L(l), R(r) {}
    };
    typedef Node* tree;
    Node* rp;
    int n;
public:
    bst():rp(),n() {}
    void insert(tree& t, Node* p) {
        if (t == NULL) t = p;
        else if (p->data < t-data) insert(t->L, p);
        else insert(t-R, p);
    }
    Node*& find(tree& t, const T& d) {       //返回二叉树根节点的子树
        if(t == NULL) return t;
        else if(p == t->data) return t;
        else if(d < t->data) return find(t->L, d);
        else return find(t->R, d);
    }
    void travel(tree t) const {
        if(t != NULL) {
            travel(t->L);
            cout << t->data << ' ';
            travel(t->R);
        }
    }
    void clear(tree& t) {
        if(t != NULL) {
            clear(t->L);
            clear(t->R);
            delete t; t=NULL;
        }
    }
    int high(tree t) {
        if(t==NULL) return 0;
    }
};

int main() {
    bst b;
    return 0;
}
