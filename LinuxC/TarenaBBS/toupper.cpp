/*
目的：将容器中的字符串中的字符全部改为大写字母
*/
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
        vector<string> svec;
        string str ;

        cout << "请向容器中输入字符串:";
        while(cin>>str)
                svec.push_back(str);

        cout << "=========================" << endl;

        cout << "输出人群中的元素:";        
        vector<string>::iterator it = svec.begin();
        for(;it!=svec.end();++it)
                cout << *it << ' ';
        cout << endl;

        cout << "=========================" << endl;

        cout << "将容器中的字符串中的字符改为大写:";        
        vector<string>::iterator sit = svec.begin();
        for(;sit!=svec.end();++sit)
        {        
                // *sit = toupper(*sit) ;//为何此处报错，该如何修改？
                cout << *sit << ' ';
        }
        cout << endl;
        return 0;
}