#include <iostream>
using namespace std;
/*��̬��Ա����������ʹ��this����Ϊ����Ҫ����Ϳ��Ե���*/

class F{
	int n;
	int d;
	void reduce(){
		//Լ��
		int mcd = maxcd(n < 0 ? -n : n, d);
		if (mcd != 1) n /= mcd, d /= mcd;
	}
	
public:
	static int maxcd(int a, int b) {   //��̬��Ա����
		if (a == 0) return b;
		return maxcd(b % a, a);
	}
	F(int n = 0, int d = 1) :n(n), d(d){        //Ĭ�ϲ�������ʼ���б�
		if (d == 0) throw "��ĸ����Ϊ��";
		reduce();
		cout << "F(" << n << '/' << d << "��\n";
	}

	friend ostream& operator<<(ostream& o, const F& f) {
		o << f.n << '/' << f.d;
		return o;
	}
	friend F operator+(const F& lh, const F& rh) {   //���������,����friend�ᱨ����
		F res(lh.n * rh.d + lh.d *rh.n ,lh.d * rh.d);  //+friend���������һ���ⲿ����Ԫ���������Բ��������������ӻᱨ��
		return res;
	}
	F operator*(const F& rh)const{				//��Ա��������һ���������Ѿ��ǵ�ǰ�����ˣ�����ֻ�ܴ�һ���������Ե�ǰ�Ķ������const
		return F (n*rh.n, d*rh.d);				//��������ֱ�Ӱ����ָ�ʡ�Ե���
	}

};

int main() {
	
	F f1;
	F f2(3);
	F f3(6, 12);

	cout << f1 << ',' << f2 << ',' << f3 << endl;
	cout << F::maxcd(12, 24) << endl;   //���þ�̬����
	
	cout << f1 + f2 << ',' << f1 + f3 << endl;
	cout << f1 + f2 + f3 << endl;		//��ʱf1+f2��һ����ʱֵ����������һ����ʱֵ������Ҫ��const,��������׳���
										//+ ����ڶ���operator+ʱ����������const���Σ������������
	cout << f2*f3 << endl;

	cout << "~f1=" << ~f1;

	int a;
	cin >> a;
}