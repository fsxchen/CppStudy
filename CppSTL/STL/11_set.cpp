#include <set>
#include <iostream>
using namespace std;
#include <string>
#include "print.h"
#include <fstream>
int main() {
    set<string> ss;
    string s;
    ifstream fin("maillist");
    if(!fin) return 1;
    while(fin >> s) ss.insert(s);
    print(ss.begin(), ss.end(), '\n');
}
