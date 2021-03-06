/*
iterator find(pos_beg, pos_end, data)
iterator find_if(pos_beg, pos_end, condition) bool condition(element)
int count(...), int count_if(...)
*/

#include <algorithm>
#include <iostream>
using namespace std;
#include <cctype>
#include <string>

bool init_upper(const string& str){
    return isupper(str[0]);
}
bool has_o(const string& str) {
    return str.find_first_of("oO") != string::npos;
}
int main() {
    string a[7] = {"abc", "good", "Day", "look", "God", "OK", "bye"};
    string* p = find(a, a + 7, "look");
    cout << (p == a+7 ? "找不到":"找到") << "look" << endl;
    p = find(a, a + 7, "book");
    cout << (p == a+7 ? "找不到":"找到") << "book" << endl;
    p = find_if(a, a+7, init_upper);
    if(p == a+7) cout << "没找到大写字母开头的" << endl;
    else cout << "找到" << *p << endl;
    cout << count_if(a, a+7, init_upper) << endl;
    cout << count_if(a, a+7, has_o) << endl;
}
