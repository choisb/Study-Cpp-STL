// search_n() �˰��� ����
// ���������� ������ ���� n �� �ݺ��Ǵ��� ã�� ������ ���.
// search_n(b,e,n,x) �˰����� ���� [b, e)�� ���������� ���� x�� n�� ������ ù ������ �ݺ��ڸ� ��ȯ
// search_n() �˰����� �����ڸ� ����ؼ� ������ f(*p,x)�� ���� ���� n�� ������ ù ������ �ݺ��ڸ� ��ȯ

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int left, int right)
{
	return abs(right - left) <= 5;
}

int main()
{
	vector<int> vec;
	vec.push_back(10);

	vec.push_back(30);
	vec.push_back(30); // 30�� �ι� �ݺ�
	vec.push_back(27);

	vec.push_back(30);
	vec.push_back(30);
	vec.push_back(30); // 30�� ���� �ݺ�

	vec.push_back(40);
	vec.push_back(50);

	cout << "vec ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	
	auto iter = search_n(vec.begin(), vec.end(), 3, 30);
	if (iter != vec.end())
	{
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}
	cout << endl;

	cout << "�����ڸ� ����� ���" << endl;
	iter = search_n(vec.begin(), vec.end(), 3, 30, Pred);
	if (iter != vec.end())
	{
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}

	return 0;
}
// [��� ���]
// vec 10 30 30 27 30 30 30 40 50
// iter : 30
// iter - 1 : 27
// iter + 1 : 30
// 
// �����ڸ� ����� ���
// iter : 30
// iter - 1 : 10
// iter + 1 : 30
