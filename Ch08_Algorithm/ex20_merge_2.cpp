// �����ڸ� Ȱ���� merge() �˰��� ����
// ���� Ư�� ���� ���ؿ� ���� ���ĵ� ���¶�� �Ϲ� ������ merge() �˰����� ����� �� ����.
// �⺻ merge() �˰����� ���� ���� ���� ����(less:<)�� ������ �����Ѵ�.
// �����ڸ� ����ϴ� ���� �Ʒ��� ���� ����Ѵ�.
// merge(b,e,b2,e2,t,f)
// ���⼭ f�� ���� �����ڷ� �� �������� Ư�� ���� �����̴�.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
struct Greater
{
	bool operator() (const T& left, const T& right)const
	{
		return left > right;
	}
};

int main()
{
	vector<int> vec1;
	vec1.push_back(80);
	vec1.push_back(70);
	vec1.push_back(60);
	vec1.push_back(20);
	vec1.push_back(10);

	vector<int> vec2;
	vec2.push_back(90);
	vec2.push_back(70);
	vec2.push_back(50);
	vec2.push_back(30);
	vec2.push_back(20);

	vector<int> vec3(10);

	// �������� ������ merge()�˰���
	auto iter_end = merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin(), Greater<int>());

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
// vec1: 80 70 60 20 10
// vec2 : 90 70 50 30 20
// vec3 : 90 80 70 70 60 50 30 20 20 10
// vec3(�պ� ������) : 90~10