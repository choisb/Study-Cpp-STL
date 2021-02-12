// find(), find_if() �˰����� ����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
	return 35 < n;
}

int main()
{
	vector<int> Vec;
	Vec.push_back(10);
	Vec.push_back(20);
	Vec.push_back(30);
	Vec.push_back(40);
	Vec.push_back(50);

	for (auto v : Vec)
		cout << v << " ";
	cout << endl;

	// ���� [Vec.begin(), Vec.end())���� 20�� ã�Ƽ� �ݺ��� ��ȯ
	auto iter = find(Vec.begin(), Vec.end(), 20);
	if (iter != Vec.end())
		cout << *iter << "�� ã�Ҵ�!" << endl;

	// ���� [Vec.begin(), Vec.end())���� 35���� ū ������ ù��° ���� ��ȯ
	iter = find_if(Vec.begin(), Vec.end(), Pred);
	if (iter != Vec.end())
		cout << "���������� 35���� ū ù ��° ����: " << *iter << endl;

	return 0;
}