// ��� ���� �Լ��� ��� ����
// plus<int>, minus<int>, mulitplies<int> ����
// negate<int>�� �����۵� x ���� �ľ���.

// [��� ���]
// vec1: 10 20 40 30 50 60
// vec2: 1 2 4 3 5 6
// vec3(vec1 + vec2) : 11 22 44 33 55 66
// vec3(vec1 - vec2) : 9 18 36 27 45 54
// vec3(vec1 ���� ���ҿ��� ��) : 10 10 20 -10 20 10
// vec3(vec1 ���� ���ҿ��� ��) : 10 200 8000 240000 12000000 720000000
// vec1 ��� ������ ��: 720000000

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

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(4);
	vec2.push_back(3);
	vec2.push_back(5);
	vec2.push_back(6);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	vector<int> vec3(6);

	// plus<int>() �Լ��� ��� ����
	transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), plus<int>());
	cout << "vec3(vec1 + vec2) : ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	// minus<int>() �Լ��� ��� ����
	transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), minus<int>());
	cout << "vec3(vec1 - vec2) : ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	// negation<int>() �Լ��� ��� ����
	//transform(vec1.begin(), vec1.end(), vec3.begin(), negate<int>());
	//cout << "vec3(-vec1) : ";
	//for (auto v : vec3)
	//	cout << v << " ";
	//cout << endl;

	// minus<int>() �Լ��� ��� ����
	adjacent_difference(vec1.begin(), vec1.end(), vec3.begin(), minus<int>());
	cout << "vec3(vec1 ���� ���ҿ��� ��) : ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	// multiplies<int>() �Լ��� ��� ����
	partial_sum(vec1.begin(), vec1.end(), vec3.begin(), multiplies<int>());
	cout << "vec3(vec1 ���� ���ҿ��� ��) : ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	// multiplies<int>() �Լ��� ��� ����
	cout << "vec1 ��� ������ ��: " << accumulate(vec1.begin(), vec1.end(), 1, multiplies<int>()) << endl;

	return 0;
}



