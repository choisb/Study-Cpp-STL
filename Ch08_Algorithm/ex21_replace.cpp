// replace() �˰��� ����
// �������� Ư�� ���Ҹ� �ٸ� ������ �����ϰ��� �Ҷ� replace()�˰����� ����Ѵ�.
// replace(b,e,x,x2) �˰����� ���� [b,e)�� x ���Ҹ� x2�� ����

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
	vec.push_back(30);
	vec.push_back(30);
	vec.push_back(50);
	vec.push_back(60);

	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	//replace
	cout << "30�� 0���� replace! " << endl;
	replace(vec.begin(), vec.end(), 30, 0);


	cout << "vec: ";
	for (auto v : vec)
		cout << v << " ";
	cout << endl;

	return 0;
}
// [��� ���]
// vec: 10 20 30 40 30 30 50 60
// 30�� 0���� replace!
// vec : 10 20 0 40 0 0 50 60