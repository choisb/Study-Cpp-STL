// count() �˰��� ����
// �ش� ������ ������ int ������ ��ȯ

// count_if()�� ����ϸ� �����ڸ� Ȱ���ؼ� ���ǿ� �´� ������ ������ ��ȯ���� �� �ִ�.
// �̶� �����ڴ� ���� �ϳ��� �޴� ���� �����ڸ� ����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return 25 < n;
}
int main()
{
	vector<int> Vec;
	Vec.push_back(10);
	Vec.push_back(20);
	Vec.push_back(30);
	Vec.push_back(40);
	Vec.push_back(50);

	Vec.push_back(30);
	Vec.push_back(30);

	for (auto v : Vec)
		cout << v << " ";
	cout << endl;

	// ���� [v.begin(), v.end())���� 30 ������ ������ ��ȯ
	int n = count(Vec.begin(), Vec.end(), 30);
	cout << "30�� ����: " << n << endl;

	// ���� [v.begin(), v.end())���� Pred() �����ڸ� �����ϴ� ������ ������ ��ȯ
	n = count_if(Vec.begin(), Vec.end(), Pred);
	cout << "25���� ū ������ ����: " << n << endl;

	return 0;
}
// [��� ���]
// 10 20 30 40 50 30 30
// 30�� ���� : 3
// 25���� ū ������ ���� : 5
