#include <iostream>
using namespace std;

class List{
    typedef int T;
    struct Node {
        T data;
        Node* next;
        Node(const T& d=T()):data(d), next(NULL){}  //零初始化,如果是基本类型，值为零，
        //如果是自建类型，则是建立对象，不传参数
    };
    Node* head;                     //头指针，并不是一个节点，只是一个地址而已，
                                    //也可以使用一个头节点。带头节点的链表
    int len;
public:
    List():head(NULL),len(0){    //构造方法，只是保存了第一个节点的地址
    }
    int size() const {
        return len;
    }
    List& push_back(const T&d) {        //这里尽量使用引用，如果不是引用？？
        insert(d, size());
        return *this;
    }
    /*
    List push_back(const T&d) {     如果不是引用，返回的时候，还会复制一份，但是这个
    insert(d, size());              时候，由于head是一样的，当析构的时候，就会两次析构
    return *this;
    }
    */
    void push_front(const T& d) {   //前插
        //Node p(d); 这样不行，因为出了这个范围d就释放了，需要使用动态内存
        // Node* p = new Node(d);
        // p->next = head;
        // head = p;
        // 有了insert的方法之后，可以这么写
        insert(d, 0);
    }
    Node*& getptr(int pos){      //找到pos处的指针,？？为什么要用引用
                                        //因为直接带回去的就是指针本身，如果是指针就不是这样了
                                        //如果返回指针p 需要p->next->next 才可以用,也就是要用二级指针
        if(pos == 0) return head;
        Node* p = head;
        for(int i = 1; i < pos; i++) {
            p = p->next;
        }
        return p->next;
    }
    void insert(const T& d, int pos) {    //在pos插入
        //Node *p = getptr(pos)   p不是链表里面的指针
        if (pos < 0 || pos > this->size()) pos = 0;
        Node*& pn = getptr(pos);      //依然是引用，不用引用，需要使用p->next->next
                                    //因为如果要修改，必须从链表里面的地址来修改
        Node* p = new Node(d);
        p->next = pn;
        pn = p;
        len++;
    }

    void travel() const {  //遍历
        Node *p = head;
        while(p != NULL) {
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    }
    void clear() {   //清空链表
        while(head != NULL) {
            Node* p = head->next;
            delete head;
            head = p;
        }
    }
    ~List() {
        cout << this << "************" << head << endl;
        clear();
    }
    void erase(int pos){    //按照位置删除
        if(pos < 0 || pos >= size()) return;   //有效位置判断
        Node*& pn = getptr(pos);        //注意，要操作的还是链表里面的地址，否则还是要用二级指针
        Node* p = pn;
        pn = pn->next;
        delete p;
        this->len--;

    }
    void remove(const T& d) {    //按照数值来操作
        int pos = -1;
        while((pos = find(d)) != -1)
            erase(pos);
    }

    int find(const T& d) const {
        Node *p = head;
        int pos = 0;
        while(p) {
            if(p->data == d) return pos;
            p = p->next; ++ pos;
        }
        return -1;
    }
    void set(int pos, const T& d) {
        if(pos < 0 || pos >= size()) return;
        getptr(pos)->data = d;
    }
    bool empty() const {return head==NULL;}
    T front() {if(empty()) throw "空"; return head->data;}
    T end()const {
        if(empty()) throw "空";
        Node *p = head;
        while(p->next != NULL){
            p = p->next;
        }
        return p->data;
    }
    void reverse() {
        Node *p = this->head;
        head = NULL;
        while(p != NULL) {
            // cout << p->data << "\t...";
            push_front(p->data);
            p = p->next;
        }
    }
    void sort(int reverse=0) {        //突然发现，没有头节点，不使用C++
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
};

int main() {
    List l;
    l.push_front(5);
    l.push_front(8);
    l.push_front(20);
    l.insert(44, 1);
    l.insert(4,10);
    l.insert(10, 100);
    l.insert(8, 3);
    l.push_back(50).push_back(60);
    l.travel();
    l.erase(1);
    l.travel();
    l.remove(8);
    l.set(l.size()-1, 500);
    l.set(l.find(5), 15);
    l.travel();
    l.reverse();
    l.travel();
    l.sort();
    cout << "the sorted list is: " << endl ;
    l.travel();
    cout << "第一个元素是:" << l.front() << "\t最后一个是:" << l.end() << "\t大小是:" << l.size() << endl;
    sizeof(l); //? =4/8其实就是一个地址
    return 0;
}
