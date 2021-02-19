// merge() �˰��� ����
// ���ĵ� �� �������� �ϳ��� ������ �������� �պ��Ϸ��� merge()�˰��� ���
// p = merge(b,e,b2,e2,t) �˰����� ���� [b,e)�� �������� ���� [b2,e2)�� �������� ������ ������ [t,p)�� �պ�
//
// ���ı��ؿ� ���� �����ڸ� ����� ���� �ִ�.

// [��� ���]
// vec1: 20 30 40 50 60
// vec2: 10 40 50 80
// vec3: 0 0 0 0 0 0 0 0 0 0 0 0
// vec1: 20 30 40 50 60
// vec2: 10 40 50 80
// vec3: 10 20 30 40 40 50 50 60 80 0 0 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(20);
	vec1.push_back(30);
	// vec1.push_back(100); ���ĵǾ����� �ʴٸ� ���� �߻�. 
	vec1.push_back(40);
	vec1.push_back(50);
	vec1.push_back(60);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(10);
	vec2.push_back(40);
	vec2.push_back(50);
	vec2.push_back(80);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	vector<int> vec3(12);

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	// vec1�������� vec2�������� ���ļ� vec3�� ����
	auto iter_end = merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	return 0;
}