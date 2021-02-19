// ���հ� ���õ� �˰��� ����
// set_intersection(): �� �������� �������� ���� �� ���
// set_difference(): �� �������� �������� ���� �� ���
// set_symmetric_difference(): �� �������� ��Ī �������� ���� �� ���
// �� �˰��� ��� ����� ���� �����Ѵ�.
//
// ���� ���ؿ� ���� ������ ���� ���.

// [��� ���]
// vec1: 10 30 40 70 80
// vec2: 10 20 50 60 70 90
// ������: 10 70
// ������: 30 40 80
// ��Ī ������: 20 30 40 50 60 80 90

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(70);
	vec1.push_back(80);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(10);
	vec2.push_back(20);
	vec2.push_back(50);
	vec2.push_back(60);
	vec2.push_back(70);
	vec2.push_back(90);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	vector<int> vec3(12);

	// set_intersection() ������
	auto iter_end = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "������: ";
	for (auto iter = vec3.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << endl;
	
	// set_difference() ������
	iter_end = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "������: ";
	for (auto iter = vec3.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << endl;

	// set_symmetric_difference() ��Ī ������
	iter_end = set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

	cout << "��Ī ������: ";
	for (auto iter = vec3.begin(); iter != iter_end; iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}



