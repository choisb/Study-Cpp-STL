// copy_backward() �˰��� ����
// copy_backward() �˰����� copy() �˰���� ���������� ���������� �ٸ� �������� ���Ҹ� �����Ҷ� ����Ѵ�.
// �ٸ� copy() �˰������ �ٸ��� �ڿ������� ���Ҹ� �����Ѵ�.
// �ڿ��� ���� ���Ҹ� �����ϱ� ������ copy()�� �ٸ��� ������ ������ �������� �ƴ� ������ �����ؾ��Ѵ�.

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

	vector<int> vec2(7); // copy�� ���ؼ� size�� 7�� vector ����

	auto iter = copy_backward(vec1.begin(), vec1.end(), vec2.end());
	cout << "vec2�� ù ����: " << *iter << endl;

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
// vec2�� ù ���� : 10
// vec1 : 10 20 30 40 50
// vec2 : 0 0 10 20 30 40 50