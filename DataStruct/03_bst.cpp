#include <iostream>
using namespace std;
typedef char T;

struct Node{
    T data;
    Node* L;
    Node* R;
    Node(const T&d):data(d),L(),R(){}       //不传参数，就是空
    Node(const T&d, Node* l, Node* r):data(d), L(l), R(r) {}
};
