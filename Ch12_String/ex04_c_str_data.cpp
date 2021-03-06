// c_str(), data() ����Լ� ��� ����
// �� ��� �Լ� ��� const char* ������ ��ȯ.
// c_str(): string ��ü�� ������ �ִ� ���ڿ��� C-style�� ���ڿ��� ��ȯ�� �� ���
// data(): '\0' ���ڸ� �������� �ʴ� ������ �迭�� ��ȯ

// [��� ���]
// '\0' ���ڷ� ������ ���ڿ�(C - style) : Hello!
// '\0' ���ڸ� �������� ���� ���ڿ� �迭 : Hello!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("Hello!");
	const char* sz;
	const char* buf;

	sz = s.c_str();
	buf = s.data();

	cout << "'\\0' ���ڷ� ������ ���ڿ� (C-style): " << sz << endl;
	cout << "'\\0' ���ڸ� �������� ���� ���ڿ� �迭: ";
	for (int i = 0; i < 6; i++)
		cout << buf[i];
	cout << endl;

	return 0;

}