// find_first_of() �˰��� ����
// �� �������� ���Ͽ� ��� ���� �� ���� ���Ұ� �ϳ��� �߰ߵǸ� �߰ߵ� ù ������ �ݺ��ڸ� ��ȯ
// �����ڸ� Ȱ���ؼ� �� ������ ����ڰ� ������ ���� �ִ�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Pred(int left, int right)
{
	return left > right;
}
int main()
{
	vector<int> Vec1;
	Vec1.push_back(10);
	Vec1.push_back(20);
	Vec1.push_back(30);
	Vec1.push_back(40);
	Vec1.push_back(50);


	cout << "Vec1 ";
	for (auto v : Vec1)
		cout << v << " ";
	cout << endl;

	vector<int> Vec2;
	Vec2.push_back(40);
	Vec2.push_back(80);
	Vec2.push_back(20);

	cout << "Vec2 ";
	for (auto v : Vec2)
		cout << v << " ";
	cout << endl;

	// Vec1���� Vec2�������� ���ҿ� ��ġ�ϴ� ���Ұ� �� �ϳ��� �ִٸ�
	// ��ġ�ϴ� �������� ù��° ���� ��ȯ
	cout << "�⺻ find_first_of()�Լ�" << endl;
	auto iter = find_first_of(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end());
	if (iter != Vec1.end())
		cout << "iter : " << *iter << endl;

	cout << "�����ڸ� ����ϴ� find_first_of()�Լ�" << endl;
	iter = find_first_of(Vec1.begin(), Vec1.end(), Vec2.begin(), Vec2.end(), Pred);
	if (iter != Vec1.end())
		cout << "iter : " << *iter << endl;

	return 0;
}
// [��� ���]
// Vec1 10 20 30 40 50
// Vec2 40 80 20
// �⺻ find_first_of()�Լ�
// iter : 20
// �����ڸ� ����ϴ� find_first_of()�Լ�
// iter : 30