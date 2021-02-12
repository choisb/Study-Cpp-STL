// copy() �˰��� ����
// copy() �˰����� ���������� �ٸ� �������� ���Ҹ� �����Ҷ� ����Ѵ�.
// copy(b, e, t) �˰����� ���� [b, e)�� �������� ���� [t, t+(e-b))�� �������� ��� �����Ѵ�.
// ���簡 ����� �� �⺻�����δ� ����� ���� ������.
// ���� ���� �����ϱ� ���ؼ��� �ݺ��� �����(insert_iterator)���� ����ؾ� �Ѵ�.
// ����� ���� �����ϱ� ���ؼ��� �ݵ�� �������� ���� ������ ��� ������ ���� �̻����� �����ؾ� �Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	vector<int> vec2(7); // copy�� ���ؼ� size 7�� vector ����

	auto iter = copy(vec1.begin(), vec1.end(), vec2.begin());
	cout << "vec2�� ������ ����: " << *(iter - 1) << endl;

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [��� ���]
// vec2�� ������ ���� : 50
// vec1 : 10 20 30 40 50
// vec2 : 10 20 30 40 50 0 0