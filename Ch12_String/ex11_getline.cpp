// getline(), ��Ʈ�� ������ >> ����
// ��Ʈ�����κ��� string ��ü�� ���ڿ��� �Է¹������� �Է� ��Ʈ�� ������ >>�� getline()�Լ��� ���
// �Է� ��Ʈ�� �����ڴ� cin >> buf ó�� ���� ���ڸ� �����ڷ� ���
// getline() �Լ��� cin.getline()ó�� ���� ���ڵ� �����Ͽ� �� ���� �Է����� ����

// [��� ���]
// �� ���ڿ� �Է�(���� ���� ����):
// abcd efg
// hello world!
// s1: abcd efg
// s2: hello world!

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;

	cout << "�� ���ڿ� �Է�(���� ���� ����): " << endl;
	getline(cin, s1);
	getline(cin, s2, '\n');
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;

	return 0;
}