//允许重复的key

#include <set>
#include <iostream>
using namespace std;
#include "print.h"
#include <string>
#include <map>

int main() {
    multiset<string> ms;
    string name;
    cout << "请输入姓名(Ctrl-D)" << endl;
    while(cin>>name) {
        ms.insert(name);
    }
    print(ms.begin(), ms.end());
    multiset<string>::iterator ib=ms.begin(), ie;
    multimap<int, string> mis;
    while(ib != ms.end()) {
        mis.insert(make_pair(ms.count(*ib), *ib));
        ib = ms.upper_bound(*ib);
    }
    print(mis.begin(), mis.end());
}
