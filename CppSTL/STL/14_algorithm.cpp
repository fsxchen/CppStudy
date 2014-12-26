#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
void add10(int& element)
{
    element += 10;
}
void print(int element)
{
    cout << element << ' ';
}
class add{
    int delta;
public:
    add(int d):delta(d){}
    void operator()(int& element){      //重载括号运算符，构造函数对象类型的函数
        element += delta;
    }
};
template <typename Iter, typename Func>

void foreach(Iter ib, Iter ie, Func f)
{
    while(ib!=ie) f(*ib++);
    }
    int main()
    {
        int a[5] = {11,22,33,44,55};
        for_each(a,a+5,add10);
        for_each(a,a+5,print);cout<<endl;
        for_each(a,a+5,add(5));
        for_each(a,a+5,print);cout<<endl;
        for_each(a,a+5,add(1));
        for_each(a,a+5,print);cout<<endl;
    }
