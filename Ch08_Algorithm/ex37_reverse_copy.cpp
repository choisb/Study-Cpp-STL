// reverse_copy() �˰��� ����
// ������ �������� ������ �������� �����ϰ��� �Ѵٸ� reverse_copy() �˰����� ���
// p = reverse_copy(b,e,t)�� ����[b,e)�� �������� ������ ������ ������ [t,p)�� �����Ѵ�.

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
	vec1.push_back(60);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2(6);

	reverse_copy(vec1.begin(), vec1.end(),vec2.begin());

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [��� ���]
// vec1: 10 20 30 40 50 60
// vec2: 60 50 40 30 20 10
