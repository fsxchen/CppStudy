#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class MyType{};
class MyException :public exception {
public:
	const char* what()const { return "�ҵ��쳣����"; }
};

void f()throw(double, int, const char*, MyType, MyException) {
	cout << "������1-5������:";
	int n;
	cin >> n;
	if (n == 1) throw MyException();
	if (n == 2)throw MyType();	//ʹ����������
	if (n == 3) throw "Hello";
	if (n == 4) throw 123;
	if (n == 5)throw 123.5;
	cout << "===========the end of f =============" << endl;
}
class ME :public exception {
	char msg[100];
public:
	ME(int n) {sprintf(msg, "�ӵ�%d���׳��쳣", n);}
	const char* waht()const throw() { return msg; }
};
void g() {
	try{
		f();
	}
	catch (const char* e) { cout << "const char * " << e << endl; }
	catch (double e) { cout << "double " << e << endl; }
	//catch (exception e) { cout << "exception:" << e.what() << endl; }
	/*������쳣����ǰ�汻����Ӧ�������࣬Ȼ����*/
	catch (MyException e) { cout << "exception" << e.what() << endl; }
	catch (exception e){ cout << "�����쳣" << endl; throw  ME(__LINE__); }
	//catch (...){ cout << "�����쳣" << endl; throw  ME(__LINE__); }//�����ں����׳��쳣
	cout << "===========the end of g =============" << endl;
}
//ÿ��catchֻ�����Ӧ��try�������������
int main() {  //�쳣����������������������׳����쳣
	try {
		g();
	}

	/*
	catch (const char* e) { cout << "const char * " << e << endl; }
	catch (double e) { cout << "double " << e << endl; }
	catch (exception e) { cout << "exception:" << e.what() << endl; }
	������쳣����ǰ�汻����Ӧ�������࣬Ȼ����
	catch (MyException e) { cout << "My Exception" << e.what() << endl; }
	�쳣����ʹ��һ����ʱ����Ҳ�ᱻ������ֱ����������ʱΪֹ
	  ����ʹ������
	  catch (exception& e) { cout << "exception:" << e.what() << endl; }
	  ��׼���ڲ��׳����쳣������exception�����࣬����catch(exception)�ܹ������׼��
	  �ڲ����е��쳣��
	  catch(...) ������Բ����κ�һ���쳣
	
	catch (...){ cout << "�����쳣" << endl; }Ҫ�������  */
	catch (...){ cout << "�����쳣" << endl; }
	cout << "===========the end of main =============" << endl;
}
/*�����쳣������Լ�д���̳�exception
  ��дwhat����
*/