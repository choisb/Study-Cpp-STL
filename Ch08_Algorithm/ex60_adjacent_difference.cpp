// adjacent_difference() �˰��� ����
// ���������� ���ҵ鰣�� ���� ���ϱ� ���ؼ��� adjacent_difference() �˰����� ���
// adjacent_difference(b,e,t) �˰����� ���� [b,e)�� �ݺ��ڰ� p�϶� (*p - *(p-1)) ������ ������ ������ [t,p)�� ����
//
// ���� ���ҿ��� ����� ���� ������ �����Ϸ��� �Լ��� ���� adjacent_difference() �˰���
// p = adjacent_difference(b,e,t,f) �˰����� ���� [b,e)�� �ݺ��ڰ� p��� f(*p, *(p-1)) ������ ������ ������ [t,p)�� ����

// [��� ���]
// vec1: 10 20 40 30 50 60 90 20
// vec2: 10 10 20 -10 20 10 30 -70
// vec2: 10 30 60 70 80 110 150 110

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int MyPlus(int left, int right)
{
	return left + right;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);
	vec1.push_back(90);
	vec1.push_back(20);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2(8);

	auto iter_end = adjacent_difference(vec1.begin(), vec1.end(), vec2.begin());

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	// ����� ���� ������ Ȱ���ϴ� adjacent_difference() �˰���
	iter_end = adjacent_difference(vec1.begin(), vec1.end(), vec2.begin(), MyPlus);
	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;
	return 0;
}

