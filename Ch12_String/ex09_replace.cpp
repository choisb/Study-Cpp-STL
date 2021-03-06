// replace() ��� �Լ� ����
// replace() ��� �Լ��� ����ϸ� ���ڳ� ���ڿ��� ��ü�� �� �ִ�.
// ��ġ(index)�� �����ϴ� ������ �ݺ��ڸ� �����ϴ� ������ �ִ�.
// ������� insert()�� ����

// [��� ���]
// s1.replace(pos, n, sz) : ABClo!
// s2.replace(pos, n, s) : ABClo!
// s3.replace(pos, n, sz, n2) : ABlo!
// s4.replace(pos, n, s, pos2, n2) : BClo!
// s5.replace(pos, n, ct, c) : AAlo!
// 
// s6.replace(iterb, itere, sz)ABClo!
// s7.replace(iterb, itere, s) : ABClo!
// s8.replace(iterb, itere, sz, ct) : ABlo!
// s9.replace(iterb, itere, ct, c) : AAAlo!
// s10.replace(iterb, itere, iterb2, itere2) : ABC

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
	string s10("Hello!");


	s1.replace(0, 3, "ABC");
	s2.replace(0, 3, t);
	s3.replace(0, 3, "ABC", 2);
	s4.replace(0, 3, t, 1, 2);

	s5.replace(0, 3, 2, 'A');

	s6.replace(s6.begin(), s6.begin()+3, "ABC");
	s7.replace(s7.begin(), s7.begin()+3, t);
	s8.replace(s8.begin(), s8.begin()+3, "ABC", 2);
	s9.replace(s9.begin(), s9.begin() + 3, 3, 'A');
	s10.replace(s10.begin(), s10.end(), t.begin(), t.end());

	// sz: '\0' ���ڿ�,  s: string ��ü, c: ����, pos: ���� ��ġ, ct: ����, n: ����, iterb: ���۹ݺ���, itere: �� �ݺ���
	cout << "s1.replace(pos, n, sz): " << s1 << endl;
	cout << "s2.replace(pos, n, s): " << s2 << endl;
	cout << "s3.replace(pos, n, sz, n2): " << s3 << endl;
	cout << "s4.replace(pos, n, s, pos2, n2): " << s4 << endl;
	cout << "s5.replace(pos, n, ct, c): " << s5 << endl << endl;
				
	cout << "s6.replace(iterb, itere, sz)" << s6 << endl; 
	cout << "s7.replace(iterb, itere, s): " << s7 << endl;
	cout << "s8.replace(iterb, itere, sz, ct): " << s8 << endl;
	cout << "s9.replace(iterb, itere, ct, c): " << s9 << endl;
	cout << "s10.replace(iterb, itere, iterb2, itere2): " << s10 << endl;

	return 0;
}