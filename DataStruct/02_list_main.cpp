#include <iostream>
typedef int T;
#include "02_list.h"
/*这个是分开版本的*/

using namespace std;
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
