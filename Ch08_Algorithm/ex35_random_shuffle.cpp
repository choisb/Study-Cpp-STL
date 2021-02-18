// random_shuffle() �˰��� ����
// ������ ������ ������ �������� �ڼ����� �Ѵٸ� random_shuffle() �˰��� ���
// random_shuffle(b,e) �˰����� ���� [b, e)�� �������� �������� �ڼ��´�.
// �ʱ�ȭ�� ���ؼ��� <cstdlib> ����� srand() ���

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);
	vec1.push_back(60);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// ���� �ʱ갪
	srand((unsigned)time(NULL));

	// ���Ҹ� �ڼ��´�.
	random_shuffle(vec1.begin(), vec1.end());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	// ���Ҹ� �ڼ��´�.
	random_shuffle(vec1.begin(), vec1.end());

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [��� ���]
// vec1: 10 20 30 40 50 60
// vec1 : 40 50 20 30 60 10
// vec1 : 40 60 50 20 10 30
