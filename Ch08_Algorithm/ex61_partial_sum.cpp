// partial_sum() �˰��� ����
// ���������� ���� ���ұ����� ���� ���ϰ��� �Ѵٸ� partial_sum()�˰��� ���
// p = partial_sum(b,e,t) �˰����� ���� [b,e)�� ���� ���ұ����� ����(����)�� ������ ������ [t,p)�� ����
//
// ���������� ���� ���ұ����� �� �Ӹ� �ƴ϶� ����� ������ �����Ϸ��� �Լ��� ������ partial_sum()�˰��� ���
// p = partial_sum(b,e,t,f) �˰����� ���� [b,e)�� ���� ���ұ����� f ������ ���� ������ ������ [t,p)�� ����.
//
// [��� ���]

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int MyMulti(int left, int right)
{
	return left * right;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2(5);
	
	auto iter_end = partial_sum(vec1.begin(), vec1.end(), vec2.begin());

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	iter_end = partial_sum(vec1.begin(), vec1.end(), vec2.begin(), MyMulti);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}

