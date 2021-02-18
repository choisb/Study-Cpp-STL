// make_heap() �˰��� ����
// �������� heap������ ����� ���ؼ��� make_heap() �˰��� ���
// make_heap(b,e) �˰����� ����[b,e)�� �������� �� ������ �����.

// [��� ���]
// vec1: 10 20 30 40 50 60 70 80
// ������: 80 50 70 40 10 60 30 20

#include <iostream>
#include <vector>
#include <algorithm>
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
	vec1.push_back(70);
	vec1.push_back(80);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	make_heap(vec1.begin(), vec1.end());

	cout << "������: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;


	return 0;
}

