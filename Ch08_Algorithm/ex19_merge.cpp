// merge() �˰��� ����
// ���ĵ� �� �������� �ϳ��� ���ĵ� �������� �պ��ϱ� ���ؼ��� nmerge() �˰����� ����Ѵ�.
// merge(b,e,b2,e2,t) �˰����� ���ı��� [b,e)�� �������� ���� [b2, e2)�� ��������
// [t, t+(e-b) + (e2 - b2))�� �������� �պ� �����Ѵ�.
// ������ ���� �ݵ�� �� �������� ���ĵǾ� �־�� �Ѵ�. ���ĵǾ� ���� �ʴٸ� ���� �߻�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);
	vec1.push_back(80);

	vector<int> vec2;
	vec2.push_back(20);
	vec2.push_back(40);
	vec2.push_back(60);
	vec2.push_back(70);
	vec2.push_back(90);

	vector<int> vec3(10);

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

	cout << "vec3(�պ� ������): " << *vec3.begin() << "~" << *(iter_end - 1) << endl;

	return 0;
}
// [��� ���]
// vec1: 10 30 50 60 80
// vec2 : 20 40 60 70 90
// vec3 : 10 20 30 40 50 60 60 70 80 90
// vec3(�պ� ������) : 10~90
