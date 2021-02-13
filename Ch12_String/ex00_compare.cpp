// boj 5052 ���� Ǯ�̸� ���ؼ� �̸� �н���
// string�� compare() �Լ� ����
//compare() ����Լ��� ���ڿ��� ���Ͽ� s1 > s2 �̸� 1 / s1 < s2 �̸� -1 / s1 == s2 �̸� 0�� ��ȯ

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("ABCDE");
	string s2("AKABC");
	const char* sz = "AKABC";

	// s : string ��ü, sz:'\0'���ڿ�, off: ������ġ, n: ����

	//s1�� s2�� ��. s1 ���� s2�� �� ŭ => 1
	cout << "s1.compare(s): " << s1.compare(s2) << endl;	

	// s1�� s2�� ���� �� 3��° ���ں��� 3���� ���ڸ� ��.
	// s1: CDE, s2: ABC �̹Ƿ� s1�� ��ŭ => -1
	cout << "s1.compare(off,n,s): " << s1.compare(2, 3, s2) << endl;

	// s1�� s2�� ���Ҷ� s1�� 1��° ���� ~ 3��° ���� / s2�� 3��° ���� ~ 5��° ���� ��
	// s1: ABC, s2: ABC �̹Ƿ� => 0
	cout << "s1.compare(off,n,s,off2,n2): " << s1.compare(0, 3, s2, 2, 3) << endl;

	// ���� �κ��� ���� �н��ϸ鼭 �ۼ�����.
	
}
