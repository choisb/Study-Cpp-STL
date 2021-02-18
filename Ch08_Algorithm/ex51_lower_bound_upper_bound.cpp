// lower_bound(), upper_bound() �˰��� ����
// ���������� ���� ���Ҹ� ã�� ���� ���� �����̳��� lower_bound(), upper_bound() ��� �Լ��� ����� �˰����� �ʿ��ϴٸ�
// lower_bound(), upper_bound() �˰����� ����Ѵ�.
// p = lower_bound(b,e,x)�� ���� [b,e)�� ���������� x ���ҿ� ���� ù ������ �ݺ��ڸ� ��ȯ
// p = upper_bound(b,e,x)�� ���� [b,e)�� ���������� x ���ҿ� ���� ������ ������ �ݺ��ڸ� ��ȯ
// ã���� �ϴ� ���Ұ� �ִ� �������� �⺻ ���� ���� less�� �ƴ϶�� ������ ������ lower_bound(), upper_bound()�� ����ؾ��Ѵ�.

// [��� ���]
// vec1: 10 20 30 30 30 40 50 60
// 30 ������ ������ [iter_lower, iter_upper): 30 30 30

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
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);
	vec1.push_back(60);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	auto iter_lower = lower_bound(vec1.begin(), vec1.end(), 30);
	auto iter_upper = upper_bound(vec1.begin(), vec1.end(), 30);

	cout << "30 ������ ������ [iter_lower, iter_upper): ";
	for (auto iter = iter_lower; iter != iter_upper; iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}



