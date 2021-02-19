// set_union() �˰��� ����
// ���ĵ� �� �������� �������� ���Ϸ��� set_union()�� ����Ѵ�.
// p = set_union(b,e,b2,e2,t) �˰����� ���� [b,e)�� ���� [b2,e2)�� �������� �������Ͽ� ������ ������ [t,p)�� �����Ѵ�.
// (�������̱� ������ �ߺ��� ���� ����)
//
// ���� ���ؿ� ���� �����ڸ� Ȱ���� ���� �ִ�.
//
// [��� ���]
// vec1: 10 20 30 40 50
// vec2: 30 50 60 70 80
// vec3: 10 20 30 40 50 60 70 80 0 0

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
	

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(30);
	vec2.push_back(50);
	vec2.push_back(60);
	vec2.push_back(70);
	vec2.push_back(80);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	vector<int>vec3(10);
	auto iter_end = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	return 0;
}

