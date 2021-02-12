// fill(), fill_n() �˰��� ����
// fill(), fill_n() �˰����� �������� Ư�� ������ ä��� ���ؼ� ���.
// fill(b, e, x) �˰����� ������ [b,e)�� x�� ä���.
// fill_n(b, n, x) �˰����� ������ [b, b+n)�� x�� ä���.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	// ���� [v.begin(), v.end())�� ��� ���Ҹ� 0���� ä��
	fill(vec.begin(), vec.end(), 0);
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	// ���� [vec.begin(), vec.begin() + 3)�� ��� ���Ҹ� 55�� ä��
	fill_n(vec.begin(), 3, 55);
	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [��� ���]
// vec: 0 0 0 0 0
// vec : 55 55 55 0 0