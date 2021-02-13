// replace_copy(), replace_copy_if() �˰��� ����
// ����ڰ� ������ ���ǿ� �´� ���Ҹ� �����Ͽ� ������ �������� �����Ϸ���
// replace_copy()�� replace_copy_if() �˰����� ����� �� �ִ�.
// replace(b,e,f,x2) �˰����� ���� [b,e)�� ������ f(*p)�� ���� ���Ҹ� x2�� ����
// ���⼭ f�� ���� �������̴�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return n <= 30;
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

	vector<int> vec2(8);	// size�� 8�� vector ����
	vector<int> vec3(8);	// size�� 8�� vector ����


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

	cout << endl;
	//vec1���� ũ�Ⱑ 30�� ���Ҹ� 0���� ��ȯ�Ͽ� vec2�� ����
	cout << "vec1���� ũ�Ⱑ 30�� ���Ҹ� 0���� ��ȯ�Ͽ� vec2�� ����" << endl;
	auto iter_end2 = replace_copy(vec1.begin(), vec1.end(), vec2.begin(), 30, 0);

	//vec1���� 30������ ���Ҹ� 0�̸� ��ȯ�Ͽ� vec3�� ����
	cout << "vec1���� 30������ ���Ҹ� 0�̸� ��ȯ�Ͽ� vec3�� ���� " << endl;
	auto iter_end3 = replace_copy_if(vec1.begin(), vec1.end(), vec3.begin(), Pred, 0);

	cout << endl;

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
// [��� ���]
// vec1: 10 20 30 40 30 30 50 60
// vec2 : 0 0 0 0 0 0 0 0
// vec3 : 0 0 0 0 0 0 0 0
// 
// vec1���� ũ�Ⱑ 30�� ���Ҹ� 0���� ��ȯ�Ͽ� vec2�� ����
// vec1���� 30������ ���Ҹ� 0�̸� ��ȯ�Ͽ� vec3�� ����
// 
// vec1 : 10 20 30 40 30 30 50 60
// vec2 : 10 20 0 40 0 0 50 60
// vec3 : 0 0 0 40 0 0 50 60
