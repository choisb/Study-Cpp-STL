// equal() �˰��� ����
// equal() �˰����� �� �������� ���Ҹ� ���Ͽ� ������ ��� true ��ȯ
// equal() �˰����� �����ڸ� ����� �� �ִ�.
// �����ڴ� �ΰ��� ���Ҹ� ���� �� �ִ� ���� �����ڸ� ����ϰ�, �����ڰ� ���� ��� equal()�� ���� ��ȯ

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// �� ���� ���̰� 5 �̸��� ��� ���� ��ȯ�ϴ� ������.
bool Pred(int left, int right)
{
	return abs(right - left) < 5;
}
int main()
{
	vector<int> Vec1;
	Vec1.push_back(10);
	Vec1.push_back(20);
	Vec1.push_back(30);

	vector<int> Vec2;
	Vec2.push_back(12);
	Vec2.push_back(21);
	Vec2.push_back(33);
	Vec2.push_back(40);
	Vec2.push_back(50);

	cout << "Vec1 : ";
	for (auto v : Vec1)
		cout << v << " ";
	cout << endl;

	cout << "Vec2 : ";
	for (auto v : Vec2)
		cout << v << " ";
	cout << endl;

	// ���� [Vec1.begin(), Vec2.end()) ��
	// ���� [Vec2.begin(), Vec2.begin() + 3) �� �������� Ȯ��
	// �⺻ equal() ���
	if (equal(Vec1.begin(), Vec1.end(), Vec2.begin()))
		cout << "�� �������� ��Ȯ�� �����ϴ�." << endl;

	// ����� ���� �����ڸ� ����ϴ� equal() ���
	if (equal(Vec1.begin(), Vec1.end(), Vec2.begin(), Pred))
		cout << "�� �������� ���� �����ϴ�." << endl;

	return 0;
}
// [��� ���]
// Vec1: 10 20 30
// Vec2 : 10 20 30 40 50
// �� �������� ���� �����ϴ�.