// swap_ranges() �˰��� ����
// �������� �������� ��� ���Ҹ� ��ȯ�ϱ� ���ؼ��� swap_ranges() �˰����� ���
// swap_ranges(b,e,b2) �˰����� [b, e)�� ������ ����[b2, b2 + (e-b))�� ��� ���Ҹ� ��ȯ.


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
	vec1.push_back(30);
	vec1.push_back(30);
	vec1.push_back(50);
	vec1.push_back(60);

	vector<int> vec2;
	vec2.push_back(11);
	vec2.push_back(21);
	vec2.push_back(31);
	vec2.push_back(41);
	vec2.push_back(31);
	vec2.push_back(31);
	vec2.push_back(51);
	vec2.push_back(61);

	cout << "vec1: ";
	for (auto v : vec1)
		cout << v << " ";
	cout << endl;

	cout << "vec2: ";
	for (auto v : vec2)
		cout << v << " ";
	cout << endl;

	swap_ranges(vec1.begin(), vec1.end(), vec2.begin());

	cout << "swap_ranges()!" << endl;

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