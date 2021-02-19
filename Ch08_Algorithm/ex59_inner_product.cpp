// inner_product() �˰��� ����
// �� �������� ����(��� ������ ���� ��)�� ���Ϸ��� inner_product() �˰����� ���
// x2 = inner_product(b,e,b2,x) �˰����� x�� �ʱ갪���� ���� [b,e)�� ���ҿ� ���� [b2,b2+e-b)�� ���� ������ x2�� ��ȯ
//
// �Լ����� ������ inner_product() �˰����� ����ϸ� �� �پ��� ���� ���� ����� ���� ������ ����
// inner_product(b,e,b2,x,f1,f2) �˰����� f1�� '+'�����̰� f2'*' �����̶��
// ���� [b,e)�� ���ҿ� ���� [b2,b2+e-b)�� �� ���ҵ鰣�� '*' ���� �� '+' ������ �����Ѵ�.

// [��� ���]

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int Plus(int left, int right)
{
	return left + right;
}
int Minus(int left, int right)
{
	return left - right;
}
int main()
{
	vector<int> vec1;
	vec1.push_back(2);
	vec1.push_back(4);
	vec1.push_back(5);
	vec1.push_back(2);
	vec1.push_back(3);


	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(3);
	vec2.push_back(3);
	vec2.push_back(2);
	vec2.push_back(2);
	vec2.push_back(4);

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	// vec1�� ve2�� ����: 2*3 + 4*3 + 5*2 + 2*2 + 3*4
	cout << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0) << endl;
	cout << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 1000) << endl;

	// �Լ��� ������ inner_product()
	// vec1�� ve2�� ����� ���� ����: 2-3 + 4-3 + 5-2 + 2-2 + 3-4
	cout << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, Plus, Minus) << endl;;
	// STL �Լ��� ��� ����
	cout << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, plus<int>(), minus<int>()) << endl;

	return 0;
}



