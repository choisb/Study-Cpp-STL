// equal_range() �˰��� ����
// ���������� ã�� ������ �ݺ��� ��(����)�� ����� �Ѵٸ� equal_range() �˰����� ����Ѵ�.
// pair(p1, p2) = equal_range(b,e,x)�� 
// ����[b,e)�� ���������� x�� ���� ���ҵ��� �̷�� �ִ� ������ ������ �ݺ��� �� (p1, p2)�� ��ȯ
// �������� ���ı����� less �����ڰ� �ƴ϶�� ������ ������ equal_range() ���

// [��� ���]
// vec1: 10 20 30 30 30 40 50 60
// 30 ������ ������ [iter_pair.first, iter_pair.second) : 30 30 30
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

	auto iter_pair = equal_range(vec1.begin(), vec1.end(), 30);

	cout << "30 ������ ������ [iter_pair.first, iter_pair.second) : ";
	for (auto iter = iter_pair.first; iter != iter_pair.second; iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}



