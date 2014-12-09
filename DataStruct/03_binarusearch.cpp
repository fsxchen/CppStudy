#include <iostream>
#include <string>

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
//这个是递归的版本
// Person* binarysearch(Person* a, int n, const string& name) {
//     if(n <= 0) return NULL;
//     int mid = n / 2;
//     Person t(name.c_str(), 0, "");
//     if(a[mid] == t) return a+mid;
//     if(t < a[mid]) return binarysearch(a, mid, name);
//     else return binarysearch(a+mid+1, n - (mid + 1), name);
// }

Person* binarysearch(Person* a, int n, const string& name){
    int b=0, e=n-1;
    Person t(name.c_str(), 0, "");
    while(b <= e) {
        int mid = (b + e) / 2;
        if(a[mid] == t) return a + mid;
        if(t < a[mid]) e = mid - 1;
        else b = mid + 1;
    }
    return NULL;
}

int main() {
    Person a[5] = {Person("张飞", 20, "蜀国"),
                    Person("刘备", 21, "蜀国"),
                    Person("曹操", 23, "魏国"),
                    Person("孙权", 22, "吴国"),
                    Person("华陀", 33, "群雄")};
    // for(int i = 0; i < 5; i++) {
    //     cout << a[i] << endl;
    // }

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
    cout << "请输入姓名：";
    cin >> name;
    Person*p = binarysearch(a, 5, name);
    if(p) cout << *p << endl;
    else cout << "找不到啊" << endl;
    return 0;
}
