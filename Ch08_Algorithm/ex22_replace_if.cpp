// replace_if() �˰��� ����
// ����ڰ� ������ ���ǿ� �´� ���Ҹ� �����Ϸ��� replace_if() �˰����� ����� �� �ִ�.
// replace(b,e,f,x2) �˰����� ���� [b,e)�� ������ f(*p)�� ���� ���Ҹ� x2�� ����
// ���⼭ f�� ���� �������̴�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return 30 <= n && n <= 50;
}

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(30);
	vec.push_back(30);
	vec.push_back(50);
	vec.push_back(60);

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	//replace_if
	cout << "30 �̻� 50 ������ ���Ҹ� 0���� replace! " << endl;
	replace_if(vec.begin(), vec.end(), Pred, 0);


	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [��� ���]
// vec: 10 20 30 40 30 30 50 60
// 30 �̻� 50 ������ ���Ҹ� 0���� replace!
// vec : 10 20 0 0 0 0 0 60