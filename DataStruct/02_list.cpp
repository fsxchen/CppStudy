#include <iostream>
typedef int T;
#include "02_list.h"

using namespace std;



int List::size() const {
    return len;
}
List& List::push_back(const T&d) {        //这里尽量使用引用，如果不是引用？？
    insert(d, size());
    return *this;
}
/*
List push_back(const T&d) {     如果不是引用，返回的时候，还会复制一份，但是这个
insert(d, size());              时候，由于head是一样的，当析构的时候，就会两次析构
return *this;
}
*/
void List::push_front(const T& d) {   //前插
    //Node p(d); 这样不行，因为出了这个范围d就释放了，需要使用动态内存
    // Node* p = new Node(d);
    // p->next = head;
    // head = p;
    // 有了insert的方法之后，可以这么写
    insert(d, 0);
}
List::Node*& List::getptr(int pos){      //找到pos处的指针,？？为什么要用引用
                                    //因为直接带回去的就是指针本身，如果是指针就不是这样了
                                    //如果返回指针p 需要p->next->next 才可以用,也就是要用二级指针
    if(pos == 0) return head;
    Node* p = head;
    for(int i = 1; i < pos; i++) {
        p = p->next;
    }
    return p->next;
}
void List::insert(const T& d, int pos) {    //在pos插入
    //Node *p = getptr(pos)   p不是链表里面的指针
    if (pos < 0 || pos > this->size()) pos = 0;
    Node*& pn = getptr(pos);      //依然是引用，不用引用，需要使用p->next->next
                                //因为如果要修改，必须从链表里面的地址来修改
    Node* p = new Node(d);
    p->next = pn;
    pn = p;
    len++;
}

void List::travel() const {  //遍历
    Node *p = head;
    while(p != NULL) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}
void List::clear() {   //清空链表
    while(head != NULL) {
        Node* p = head->next;
        delete head;
        head = p;
    }
}
List::~List() {
    cout << this << "************" << head << endl;
    clear();
}
void List::erase(int pos){    //按照位置删除
    if(pos < 0 || pos >= size()) return;   //有效位置判断
    Node*& pn = getptr(pos);        //注意，要操作的还是链表里面的地址，否则还是要用二级指针
    Node* p = pn;
    pn = pn->next;
    delete p;
    this->len--;

}
void List::remove(const T& d) {    //按照数值来操作
    int pos = -1;
    while((pos = find(d)) != -1)
        erase(pos);
}

int List::find(const T& d) const {
    Node *p = head;
    int pos = 0;
    while(p) {
        if(p->data == d) return pos;
        p = p->next; ++ pos;
    }
    return -1;
}
void List::set(int pos, const T& d) {
    if(pos < 0 || pos >= size()) return;
    getptr(pos)->data = d;
}
bool List::empty() const {return head==NULL;}
T List::front() {if(empty()) throw "空"; return head->data;}
T List::end()const {
    if(empty()) throw "空";
    Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    return p->data;
}
void List::reverse() {
    Node *p = this->head;
    head = NULL;
    while(p != NULL) {
        // cout << p->data << "\t...";
        push_front(p->data);
        p = p->next;
    }
}
void List::sort(int reverse) {        //突然发现，没有头节点，不使用C++
    Node* p = head;           //里面的引用还是比较难实现的啊
    T tmp;
    while(p != NULL) {          //这里采用的是冒泡法排序
        Node* q = p->next;      //这里交换的数据，不是指针
        while(q != NULL) {
            if(p->data > q->data) {
                tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
            q = q->next;
        }
        p = p->next;
    }
}
