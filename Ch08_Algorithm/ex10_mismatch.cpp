// mismatch() �˰��� ����
// mismatch() �˰����� �� ���� ������ ������ ���ϸ鼭
// ���� �ٸ� ���Ұ� �߰ߵǴ� ù ������ �ݺ��� ���� ��ȯ�Ѵ�.
// mismatch() �˰����� ������ �������ε� ��� �� �� �ִ�.

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
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	cout << "vec1 ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	vector<int> vec2;
	vec2.push_back(10);
	vec2.push_back(20);
	vec2.push_back(30);
	vec2.push_back(42);
	vec2.push_back(70);

	cout << "vec2 ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	auto iter_pair = mismatch(vec1.begin(), vec1.end(), vec2.begin());
	cout << "vec1: " << *iter_pair.first << ", " << "vec2: " << *iter_pair.second << endl;

	cout << endl;

	cout<< "������ ��� ����" << endl;

	// �������� 5 ������ ������ ������ �����ϴ� Pred()�Լ�
	iter_pair = mismatch(vec1.begin(), vec1.end(), vec2.begin(), Pred);
	cout << "vec1: " << *iter_pair.first << ", " << "vec2: " << *iter_pair.second << endl;

	return 0;
}
// [��� ���]
// vec1 10 20 30 40 50
// vec2 10 20 30 42 70
// vec1: 40, vec2 : 42
// 
// ������ ��� ����
// vec1 : 50, vec2 : 70