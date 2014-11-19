#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	cout.width(10);
	cout << 123 << ',' << 123 << endl;  //ֻ��ǰ�����Ч
	cout.width(2);
	cout << 123 << ',' << 123 << endl;	//ָ��������ȣ���������ˣ���

	cout << setw(10) << 123 << ',' << hex<< 123 << endl;	//��ʽ���Ʒ���������hex����,
															//+û�в���,һ��ָ��������ȫ����Ч
															//����������Ҫһ��ͷ�ļ�iomanip
	cout.setf(ios::hex, ios::basefield);//oct, dec, showbase)				//�������õĸ�ʽ��־
												//����������ֻ��ʹ��16����

	cout.setf(ios::hex, ios::basefield);	//ʹ�ø�ʽ���Ʒ�����Ƚϼ�
	cout << showbase << 123 << endl;
	cout.unsetf(ios::hex);
	cout << 123 << endl;
	
	cout << 5.0 << endl;
	cout << showpoint << 5.0 << endl;		//������ʾС����,��Ч���ֱ���6λ
											//scientific  ��ѧ������
	//cout << scientific << 5.0 << endl;

	cout.precision(3);
	cout << 95.0 << endl;//ָ������ ���95.0  �������3����Ч��

	cout << fixed << 95.0 << endl;		//��ʾ��С����������Чλ��
	cout << setprecision(2) << 800.0 << endl;		//ʹ�ø�ʽ���Ʒ�
	cout << showpos << 123 << ',' << 45.6 << endl;	//���������ϣ�
	cout << uppercase << hex << 123 << ", " << scientific << 95.0 << endl;		//16���ơ���ѧ��������д
	//�������������
	cout << dec << setw(10) << 123 << endl;		//Ĭ�����Ҷ���
	cout << left << setw(10) << 123 << endl;	//�����
	//ָ������ַ�
	cout.fill('#');
	cout << dec << setw(10) << 123 << endl;		//Ĭ�����Ҷ���
	cout << left << setw(10) << 123 << endl;	//�����
	cout << setfill('*') << left<< setw(10) << 123 << endl;
	cout << internal << setw(10) << 234 << endl;  //����
	cout << right << setw(10) << 234 << endl;
	
	/*

	long long int t = 0x1234567887654321;
	//      0xffff0000
	//0xffffffff
	int a, b;
	char *c;
	

	for (int i = 0; i < 8; i++) {
		c = (char *)&t;
		cout << hex << int(*c) << endl;
		t = t >> 8;
		//cout << hex << t << endl;
	}
	
	*/
	int aaaa;
	cin >> aaaa;
}