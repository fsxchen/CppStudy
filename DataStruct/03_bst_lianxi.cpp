#include <iostream>
#include <iomanip>
using namespace std;
typedef char T;

//这里的二叉树满足以下条件
//左子树 < 根节点 < 右子树

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
    void clear() {clear(rp); n = 0;}
    ~bst() {clear();}
    void insert(const T& d) {insert(rp, new Node(d)); ++n;}
    tree& find(const T& d) {return find(rp, d);}
    void travel() const {travel(rp); cout << endl;}
    void printTree() const {printTree(rp, 0, '*'); }
    bool empty() const{return rp==NULL;}
    //如何删除节点
    bool remove(const T& d){
        tree& t = find(d);
        if(t == NULL) return false;
        Node* p = t ;
        if(t->L != NULL) insert(t->R, t->L);
        t = t->R;
        delete p;
        --n;
        return true;
    }

    const T& root() const {if(!rp) throw "空"; return rp->data;}

    //修改数据？先删掉，然后插入
    void update(const T& olddata, const T& newdata) {
        if(remove(olddata)) insert(newdata);
    }
    int size() const {return n;}
    void insert(tree& t, Node* p) {
        if (t == NULL) t = p;
        else if (p->data < t->data) insert(t->L, p);
        else insert(t->R, p);
    }
    Node*& find(tree& t, const T& d) {       //返回二叉树根节点的子树
        if(t == NULL) return t;
        else if(d == t->data) return t;
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
        int lh = high(t->L);
        int rh = high(t->R);
        return 1 + max(lh, rh);
    }
    void printTree(tree t, int space, char sign) const {
        if(t == NULL) return;
        printTree(t->R, space+3, '/');
        cout << setw(space+1) << sign << t->data << endl;
        printTree(t->L, space+3, '\\');
    }
};


int main() {
    bst b;
    b.insert('k'); b.insert('s'); b.insert('f');b.insert('t');
    b.insert('a'); b.insert('m'); b.insert('x');
    // b.travel();
    // b.remove('s');b.remove('k'); b.remove('a');
    b.update('f', 'z');
    cout << "the root is" << b.root() << endl;
    b.printTree();
    // b.travel();
    while(!b.empty()) b.remove(b.root());
        // cout << "size is " << b.size() << endl;
        return 0;
    }
