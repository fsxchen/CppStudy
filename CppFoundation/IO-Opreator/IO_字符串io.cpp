#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Point {
	int x;
	int y;
public:
	Point(int x, int y) :x(x), y(y) {}
	friend ostream& operator<<(ostream& o, const Point& p) {
		return o << '(' << p.x << ',' << p.y << ')';
	}
};

int main() {

	string s = "12345 6.78 X hello 234 100";
	istringstream is(s);
	int a, b, c;
	double d;
	char e;
	char buf[100];
	is >> a >> d >> e >> buf >> oct >> b >> hex >> c;
	cout << "a=" << a << ", b=" << b << ", c=" << c << ", d="
		<< d << ", e" << ", buf" << buf << endl;
	ostringstream os;
	Point p(3, 5);
	os  << "a=" << a << ", b=" << b << ", c=" << c << ", d="
		<< d << ", e" << ", buf" << buf << ", p=" <<p;
	cout << "++++++++++++++++++++\n";
	cout << os.str() << endl;
	cout << os.str()[7] << endl;
	cout << "++++++++++++++++++++\n";
	int aaaa;
	cin >> aaaa;
}