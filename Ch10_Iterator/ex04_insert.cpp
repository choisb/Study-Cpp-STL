// ���� �ݺ��� ����� insert() ����

// [��� ���]
// vec1: 10 20 30 40 50
// vec2: 10 20 30 40 50

#include <iostream>
#include <vector>
#include <iterator>
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

	vector<int> vec2;
	// copy(vec1.begin(), vec1.end(), vec2.begin()); ����� ���� �����ϱ� ������ size�� 0�� vec2���� ���� �߻�.

	// ���Ը��
	copy(vec1.begin(), vec1.end(), inserter<vector<int>>(vec2, vec2.begin()));

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	return 0;
}



