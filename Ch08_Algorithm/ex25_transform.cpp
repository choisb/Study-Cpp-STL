// transform() �˰��� ����
// �������� ��� ���ҿ� ������� ��å�� �ݿ��Ϸ��� �Ϲ������� for_each(), transform() �˰����� ����Ѵ�.
// �� ���� ���̴� for_each()�� ������ �������� ��������� �����ϴ� �ݸ�
// transform() �˰����� �������� �������� ��������� �����Ѵ�. (����� ����)
// transform(b,e,b2,f)�� ������ ����[b, e)�� f(*p)�� ���� ������ ����[b2, b2 +(e-b))�� �����Ѵ�.
//
// ���� �� �������� ���� �����Ͽ� �� 3�� �������� �����ϱ� ���ؼ��� transform(b,e,b2,t,f)�� ����Ѵ�.
// �̴� ���� [b, e) �������� [b2, b2+(e-b))�� �������� �ݺ��ڸ� p, q�� �Ҷ� f(*p, *q)�� ����
// ������ [t, t+(e-b))�� �����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Func(int n)
{
	return n + 5;
}
int Plus(int left, int right)
{
	return left + right;
}

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);

	vector<int> vec2(8);

	transform(vec1.begin(), vec1.end(), vec2.begin(),Func);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	// �ڱ� �ڽ��� �������� �����ϸ� �ڽ��� ���Ҹ� ���� �� ���� �ִ�.
	transform(vec1.begin(), vec1.end(), vec1.begin(), Func);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec3(8);
	
	// vec1�� ���ҵ�� vec2�� ���ҵ��� Plus() �����Ͽ� vec3�� ����
	transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), Plus);

	cout << "vec3: ";
	for (auto v : vec3)
		cout << v << " ";
	cout << endl;

	return 0;
}
