// find_end() �˰��� ����
// find_end(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end())
// Vec1�� ���������� Vec2�� �������� ������ �������� �ִ��� Ž��
// ��ġ�ϴ� �������� ��������� ������ �������� ù ���� �ݺ��ڸ� ��ȯ

// find_end() �˰��� �����ڸ� ����Ͽ� ������ �񱳸� ����ڰ� ������ ���� �ִ�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Pred(int left, int right)
{
	return left >= right;
}
int main()
{
	vector<int> Vec1;
	Vec1.push_back(5);

	Vec1.push_back(20);
	Vec1.push_back(30);
	Vec1.push_back(40);

	Vec1.push_back(50);

	Vec1.push_back(20);
	Vec1.push_back(300);
	Vec1.push_back(40);

	Vec1.push_back(50);

	cout << "Vec1 ";
	for (auto v : Vec1)
		cout << v << " ";
	cout << endl;

	vector<int> Vec2;
	Vec2.push_back(20);
	Vec2.push_back(30);
	Vec2.push_back(40);

	cout << "Vec2 ";
	for (auto v : Vec2)
		cout << v << " ";
	cout << endl;

	//Vec1���� Vec2������ ������ ������ �������� �ִٸ� ���ۿ����� �ݺ��� ��ȯ
	auto iter = find_end(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end());
	if (iter != Vec1.end())
	{
		//��ġ�ϴ� ������ �������� ù ������ �ݺ��� iter
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}

	iter = find_end(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), Pred);
	if (iter != Vec1.end())
	{
		//��ġ�ϴ� ������ �������� ù ������ �ݺ��� iter
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
	}

	return 0;
}
// [��� ���]
// Vec1 5 20 30 40 50 20 300 40 50
// Vec2 20 30 40
// iter : 20
// iter - 1 : 5
// iter + 1 : 30
// iter : 300
// iter - 1 : 20
// iter + 1 : 40