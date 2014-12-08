#include <iostream>
using namespace std;

class Person{
    string name;
    int age;
    string addr;
public:
    Person(const char* n, int a, const char* ad)
    :name(n), age(a), addr(ad) {}
    friend bool operator<(const Person& a, const Person& b) {
        return a.name<b.name;
    }
    friend bool operator==(const Person& a, const Person& b) {
        return a.name == b.name;
    }
    friend ostream& operator<<(ostream& o, const Person& a) {
        o << a.name << ':' << a.age << ',' << a.addr;
        return o;
    }
};
int main() {
    Person a[5] = {Person("张飞", 20, "蜀国"),
                    Person("刘备", 21, "蜀国"),
                    Person("曹操", 23, "魏国"),
                    Person("孙权", 22, "吴国"),
                    Person("华陀", 33, "群雄")};
    for(int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }

    for(int i=0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (a[j] < a[i]){
                swap(a[j], a[i]);
            }
        }
    }

    for(int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }
    string name;
    // cout << "请输入姓名：";
    // cin >> name;
    if ("刘备" < "曹操")
        cout << "that is right\n";
    else {
        cout << "why is that\n";
    }
    return 0;
}
