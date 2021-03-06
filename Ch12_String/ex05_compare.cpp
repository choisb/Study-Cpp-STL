// compare()����Լ� ��� ����
// ���ڿ� �� ����(== , >, < ��)�� ��ü ���ڿ��� �������� compare() ��� �Լ��� �κ� ���ڿ��� ���� �� �ִ�.
//compare() ����Լ��� ���ڿ��� ���Ͽ� s1 > s2 �̸� 1 / s1 < s2 �̸� -1 / s1 == s2 �̸� 0�� ��ȯ

// [��� ���]
// s1.compare(s) : -1
// s1.compare(off, n, s) : 1
// s1.compare(off, n, s, off2, n2) : 0
// s1.compare(sz) : -1
// s1.compare(off, n, sz) : 1
// s1.compare(off, n, sz, off2, n2) : 0

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("ABCDE");
	string s2("AKABC");
	const char* sz = "AKABC";

	// s : string ��ü, sz:'\0'���ڿ�, off: ������ġ, n: ����

	//s1�� s2�� ��.
	// s1: ABCDE, s2: AKABC �̹Ƿ� -1
	cout << "s1.compare(s): " << s1.compare(s2) << endl;	

	// s1�� s2�� ���� �� 3��° ���ں��� 3���� ���ڸ� ��.
	// s1: CDE, s2: ABC �̹Ƿ� s1�̹Ƿ� 1
	cout << "s1.compare(off,n,s): " << s1.compare(2, 3, s2) << endl;

	// s1�� s2�� ���Ҷ� s1�� 1��° ���� ~ 3��° ���� / s2�� 3��° ���� ~ 5��° ���� ��
	// s1: ABC, s2: ABC �̹Ƿ� => 0
	cout << "s1.compare(off,n,s,off2,n2): " << s1.compare(0, 3, s2, 2, 3) << endl;

	// s1�� '\0'���ڿ� ��
	// s1: ABCDE, sz: AKABC �̹Ƿ� -1
	cout << "s1.compare(sz): " << s1.compare(sz) << endl;

	// s1�� '\0'���ڿ��� ���� ��  3��° ���ں��� 3���� ���ڸ� ��.
	// s1: CDE, sz: ABC �̹Ƿ� 1
	cout << "s1.compare(off, n, sz): " << s1.compare(2, 3, sz) << endl;

	// s1�� '\0'���ڿ��� ���Ҷ� s1�� 1��° ���� ~ 3��° ���ڸ� '\0'���ڿ��� 3��° ���� ~ 5��° ���� ��
	// s1: ABC, sz: ABC �̹Ƿ� 0
	cout << "s1.compare(off,n,sz,off2,n2): " << s1.compare(0, 3, sz, 2, 3) << endl;

}
