// includes() �˰��� ����
// �� �������� �ٸ� �������� �κ� �������� �Ǵ��Ϸ��� includes() �˰����� ���
// includes(b,e,b2,e2) �˰����� ���� [b2,e2)�� ���Ұ� ���� [b,e)�� ���ҿ� ���ԵǸ� true, �ƴϸ� false ��ȯ
// ������ ������ f�� �񱳿� ���.

// [��� ���]
// vec1: 10 20 30 40 50
// vec2: 10 20 30
// vec3: 10 20 60
// vec2�� vec1�� �κ� ����
// vec3�� vec1�� �κ� ������ �ƴ�

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
	vec2.push_back(10);
	vec2.push_back(20);
	vec2.push_back(30);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	vector<int> vec3;
	vec3.push_back(10);
	vec3.push_back(20);
	vec3.push_back(60);

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	if (includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()))
		cout << "vec2�� vec1�� �κ� ����" << endl;
	else
		cout << "vec2�� vec1�� �κ� ������ �ƴ�" << endl;

	if (includes(vec1.begin(), vec1.end(), vec3.begin(), vec3.end()))
		cout << "vec3�� vec1�� �κ� ����" << endl;
	else
		cout << "vec3�� vec1�� �κ� ������ �ƴ�" << endl;


	return 0;
}



