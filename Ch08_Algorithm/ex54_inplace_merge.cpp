// inplace_merge() �˰��� ����
// �ϳ��� �������� �� �������� ������ �ִٸ� inplace_merge(b,m,e)�� ����Ͽ� �ϳ��� �������� ���� ����
// inplace_merge(b,m,e) �˰����� ���ĵ� [b,m)�� �������� ���ĵ� [m,e)�� �������� ���ĵ� [b,e) �������� �պ�
// ���ı��ؿ� ���� �����ڸ� ����� �� �ִ�.

// [��� ���]
// vec1: 10 20 40 60 70 80 10 30 40 50
// vec1: 10 10 20 30 40 40 50 60 70 80

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(40);
	vec1.push_back(60);
	vec1.push_back(70);
	vec1.push_back(80);

	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	auto middle = vec1.begin() + 6;

	inplace_merge(vec1.begin(), middle, vec1.end());
	
	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}



