// lexicographical_compare() �˰��� ����
// lexicographical_compare(b, e, b2, e2) ��
// ������ [b, e)�� [b2, e2)�� ��� ���Ҹ� ���ڿ� ó�� ���Ͽ� ���� ������ ��ȯ
// �⺻������ (less: <) �����ڸ� ����Ѵ�.
// 
// lexicographical_compare(b, e, b2, e2, f) ó��
// ����ڰ� �񱳱��� �����ڸ� ���� ������ �� �ִ�.
// Ȥ�� STL�� �⺻ greater, less�� ����� ���� �ִ�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename T>
struct MyLess
{
	bool operator()(const T& left, const T& right) const
	{
		return left < right;
	}
};

int main()
{
	vector<int> Vec1;
	Vec1.push_back(10);
	Vec1.push_back(20);
	Vec1.push_back(30);

	vector<int> Vec2;
	Vec2.push_back(10);
	Vec2.push_back(20);
	Vec2.push_back(50);

	vector<int> Vec3;
	Vec3.push_back(10);
	Vec3.push_back(20);
	Vec3.push_back(30);

	if (lexicographical_compare(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end()))
		cout << "v1 < v2" << endl;
	else
		cout << "v1 >= v2" << endl;

	if (lexicographical_compare(Vec1.begin(), Vec1.end(), Vec3.begin(), Vec3.end()))
		cout << "v1 < v3" << endl;
	else
		cout << "v1 >= v3" << endl;

	cout << "STL less�� ����� v1�� v2�� ��: ";
	cout << lexicographical_compare(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), less<int>()) << endl;

	cout << "STL greater�� ����� v1�� v2�� ��: ";
	cout << lexicographical_compare(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), greater<int>()) << endl;

	cout << "������� MyLess�� ����� v1�� v2�� ��: ";
	cout << lexicographical_compare(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), MyLess<int>()) << endl;

	return 0;
}
// [��� ���]
// v1 < v2
// v1 >= v3
// STL less�� ����� v1�� v2�� �� : 1
// STL greater�� ����� v1�� v2�� �� : 0
// ������� MyLess�� ����� v1�� v2�� �� : 1