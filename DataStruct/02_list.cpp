#include <iostream>
using namespace std;

typedef int T;
class List{
    struct Node {
        T data;
        Node* next;
        Node(const T& d=T()):data(d), next(NULL){}  //零初始化,如果是基本类型，值为零，
                                                    //如果是自建类型，则是建立对象，不传参数
    };
    Node* head;                     //头指针，并不是一个节点，只是一个地址而已，
                                    //也可以使用一个头节点。带头节点的链表
public:
    List():head(NULL){    //构造方法，只是保存了第一个节点的地址
    }
    void push_front(const T& d) {   //前插
        //Node p(d); 这样不行，因为出了这个范围d就释放了，需要使用动态内存
        Node* p = new Node(d);
        p->next = head;
        head = p;
    }
    Node*& getptr(int pos){      //找到pos处的指针,？？为什么要用引用
                                        //因为直接带回去的就是指针本身，如果是指针就不是这样了
                                        //如果返回指针p 需要p->next->next 才可以用
        if(pos == 0) return head;
        Node* p = head;
        for(int i = 1; i < pos; i++) {
            p = p->next;
        }
        return p->next;
    }
    void insert(const T& d, int pos) {    //在pos插入
        //Node *p = getptr(pos)   p不是链表里面的指针
        Node*& pn = getptr(pos);      //依然是引用，不用引用，需要使用p->next->next
                                    //因为如果要修改，必须从链表里面的地址来修改
        Node* p = new Node(d);
        p->next = pn;
        pn = p;
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
        clear();
    }
};

int main() {
    List l;
    l.push_front(5);
    l.push_front(8);
    l.push_front(20);
    l.insert(44, 1);
    l.travel();
    sizeof(l); //? =4/8其实就是一个地址
    return 0;
}
