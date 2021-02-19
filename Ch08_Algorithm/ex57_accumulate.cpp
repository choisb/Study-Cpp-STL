// ��ġ�˰����� ����ϱ� ���ؼ��� <numeric> ����� �����ؾ���.
// accumulate() �˰��� ����
// �������� ��� ���ҿ� ���� ������ ���ϱ� ���ؼ� accumulate()�˰��� ���.
// for_each()�� transform()�˰����� ����� ���� ������, �̵��� �������� ����ϱ� ���� �Լ��ڸ� ����ؾ� �ϹǷ� ���� ������.
// x2 = accumulate(b,e,x) �˰����� x�� �ʱⰪ���� �� ���� [b,e)�� ��� ���� ���� x2�� ��ȯ

// [��� ���]
// vec1: 10 20 30 40 50
// 150
// 650

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

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

	cout << accumulate(vec1.begin(), vec1.end(), 0) << endl;
	cout << accumulate(vec1.begin(), vec1.end(), 500) << endl;


	return 0;
}



