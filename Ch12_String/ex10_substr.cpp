// substr() ��� �Լ� ����
// substr() ��� �Լ��� string ��ü�� �Ϻ� ���ڿ��� �����ϰ��� �� �� ���
// 
// substr(pos, n)�� pos(index)�� ��ġ���� n�� ��ŭ�� ���ڿ��� ��ȯ
// ���� n�� string::npos�� �����ϸ� ���ڿ��� ������ ���ڱ����� �ȴ�.

// [��� ���]
// substr(0) - 0���� ������ : Hello!
// substr(0, npos) - 0���� ������ : Hello!
// substr(0, 2) - 0���� 2�� : He
// substr(2, 3) - 2���� 3�� : llo
// substr(2, npos) - 2���� ������ : llo!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string t("Hello!");
	string s1, s2, s3, s4, s5;

	s1 = t.substr(0);
	s2 = t.substr(0, string::npos);

	s3 = t.substr(0, 2);
	s4 = t.substr(2, 3);
	s5 = t.substr(2, string::npos);

	cout << "substr(0) - 0���� ������: " << s1 << endl;
	cout << "substr(0, npos) - 0���� ������: " << s2 << endl;
	cout << "substr(0, 2) - 0���� 2��: " << s3 << endl;
	cout << "substr(2, 3) - 2���� 3��: " << s4 << endl;
	cout << "substr(2, npos) - 2���� ������: " << s5 << endl;

	return 0;
}