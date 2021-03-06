// insert() ��� �Լ� ����
// insert() ��� �Լ��� index ��ġ�� �ݺ��ڰ� ����Ű�� ��ġ�� ���ڳ� ���ڿ��� ����
// �ٸ� �����̳�ó�� ���� ��ġ�� ����Ű�� ������ ���ʿ� ����

// [��� ���]
// s1.insert(pos, sz) : HABCello!
// s2.insert(pos, sz, n) : HABello!
// s3.insert(pos, s) : HABCello!
// s4.insert(pos, s, off, n) : HBCello!
// s5.insert(pos, n, c) : HAAAello!
// 
// s6.insert(iter)����
// s7.insert(iter, c) : HAello!
// s8.insert(iter, n, c) : HAAAello!
// s9.insert(iter1, s.begin(), s.end()) : HABCello!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string t("ABC");

	string s1("Hello!");
	string s2("Hello!");
	string s3("Hello!");
	string s4("Hello!");
	string s5("Hello!");
	string s6("Hello!");
	string s7("Hello!");
	string s8("Hello!");
	string s9("Hello!");

	s1.insert(1, "ABC");
	s2.insert(1, "ABC", 2);
	s3.insert(1, t);
	s4.insert(1, t, 1, 2);
	s5.insert(1, 3, 'A');

	// s6.insert(s6.begin() + 1); // s6.insert(iter) �� ���µ�?
	s7.insert(s7.begin() + 1, 'A');
	s8.insert(s8.begin() + 1, 3, 'A');
	s9.insert(s9.begin() + 1, t.begin(), t.end());

	// sz: '\0' ���ڿ�,  s: string ��ü, c: ����, pos: ���� ��ġ, off: ��ġ, n: ����, iter: �ݺ���, p: ������
	cout << "s1.insert(pos, sz): " << s1 << endl;
	cout << "s2.insert(pos, sz, n): " << s2 << endl;
	cout << "s3.insert(pos, s): " << s3 << endl;
	cout << "s4.insert(pos, s, off, n): " << s4 << endl;
	cout << "s5.insert(pos, n, c): " << s5 << endl<<endl;

	cout << "s6.insert(iter)" << "����" << endl; // s6.insert(iter) �� ���µ�?
	cout << "s7.insert(iter, c): " << s7 << endl;
	cout << "s8.insert(iter, n, c): " << s8 << endl;
	cout << "s9.insert(iter1, s.begin(), s.end()): " << s9 << endl;

	return 0;
}