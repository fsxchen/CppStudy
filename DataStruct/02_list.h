#ifndef LIST_H
#define LIST_H 1
class List{
    struct Node {
        T data;
        Node* next;
        Node(const T& d=T()):data(d), next(NULL){}
    };
    Node* head;
    int len;
public:
    List():head(NULL),len(0){}
    int size() const ;
    List& push_back(const T&d) ;
    void push_front(const T& d);
    Node*& getptr(int pos);
    void insert(const T& d, int pos);

    void travel() const;
    void clear();
    ~List();
    void erase(int pos);
    void remove(const T& d);
    T find(const T& d) const;
    void set(int pos, const T& d);
    bool empty() const;
    const T& front()const;
    const T& end()const;
    void reverse();
    void sort(int reverse=0);
};
#endif
