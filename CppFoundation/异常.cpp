#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class MyType{};
class MyException :public exception {
public:
	const char* what()const { return "我的异常类型"; }
};

void f()throw(double, int, const char*, MyType, MyException) {
	cout << "请输入1-5的整数:";
	int n;
	cin >> n;
	if (n == 1) throw MyException();
	if (n == 2)throw MyType();	//使用匿名对象
	if (n == 3) throw "Hello";
	if (n == 4) throw 123;
	if (n == 5)throw 123.5;
	cout << "===========the end of f =============" << endl;
}
class ME :public exception {
	char msg[100];
public:
	ME(int n) {sprintf(msg, "从第%d行抛出异常", n);}
	const char* waht()const throw() { return msg; }
};
void g() {
	try{
		f();
	}
	catch (const char* e) { cout << "const char * " << e << endl; }
	catch (double e) { cout << "double " << e << endl; }
	//catch (exception e) { cout << "exception:" << e.what() << endl; }
	/*后面的异常会在前面被捕获，应该先子类，然后父类*/
	catch (MyException e) { cout << "exception" << e.what() << endl; }
	catch (exception e){ cout << "其他异常" << endl; throw  ME(__LINE__); }
	//catch (...){ cout << "其他异常" << endl; throw  ME(__LINE__); }//重新在后面抛出异常
	cout << "===========the end of g =============" << endl;
}
//每个catch只负责对应的try语句块里面的数据
int main() {  //异常申明，申明这个函数可能抛出的异常
	try {
		g();
	}

	/*
	catch (const char* e) { cout << "const char * " << e << endl; }
	catch (double e) { cout << "double " << e << endl; }
	catch (exception e) { cout << "exception:" << e.what() << endl; }
	后面的异常会在前面被捕获，应该先子类，然后父类
	catch (MyException e) { cout << "My Exception" << e.what() << endl; }
	异常对象即使是一个临时对象，也会被保留到直到它被处理时为止
	  可以使用引用
	  catch (exception& e) { cout << "exception:" << e.what() << endl; }
	  标准库内部抛出的异常，都是exception的子类，所以catch(exception)能够捕获标准库
	  内部所有的异常。
	  catch(...) 这个可以捕获任何一个异常
	
	catch (...){ cout << "其他异常" << endl; }要放在最后啊  */
	catch (...){ cout << "其他异常" << endl; }
	cout << "===========the end of main =============" << endl;
}
/*处理异常，最好自己写，继承exception
  重写what方法
*/