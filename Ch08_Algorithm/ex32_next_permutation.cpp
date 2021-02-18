// next_permutation() �˰��� ����
// ������ ������ ����ó�� ������ �� next_permutation()�� prev_permutation()�˰����� ���
// next_permutation(b,e)�� ���� [b,e)�� �������� ���� ������ �������� �ǰ� �Ѵ�.
// ������ �����̶�� false�� ��ȯ�ϸ�, �ƴϸ� true�� ��ȯ�Ѵ�.
// ���� ������ �������� �ǵ��� �ϱ� ���ؼ��� prev_premutation(b,e)�� ����Ѵ�.
// �⺻������ ������ ������ �������̸�, ����ڰ� �����ڸ� ����Ͽ� ������ ���� ���� �ִ�.

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

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;
	while (next_permutation(vec1.begin(), vec1.end()))
	{
		cout << "next> ";
		cout << "vec1: ";
		for (auto v : vec1)
			cout << v << " ";
		cout << endl;
	}
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	prev_permutation(vec1.begin(), vec1.end());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;
	while (prev_permutation(vec1.begin(), vec1.end()))
	{
		cout << "prev> ";

		cout << "vec1: ";
		for (auto v : vec1)
			cout << v << " ";
		cout << endl;
	}
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [��� ���]
// vec1: 10 20 30
// next > vec1: 10 30 20
// next > vec1: 20 10 30
// next > vec1: 20 30 10
// next > vec1: 30 10 20
// next > vec1: 30 20 10
// vec1 : 10 20 30
// vec1 : 30 20 10
// prev > vec1: 30 10 20
// prev > vec1: 20 30 10
// prev > vec1: 20 10 30
// prev > vec1: 10 30 20
// prev > vec1: 10 20 30
// vec1 : 30 20 10